#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *convert(vector<int> v, int n, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(v[mid]);
    Node *left_Root = convert(v, n, l, mid - 1);
    Node *right_Root = convert(v, n, mid + 1, r);
    root->left = left_Root;
    root->right = right_Root;
    return root;
}
// in order
void in_Order(Node *root)
{
    if (root == NULL)
        return;
    in_Order(root->left);
    cout << root->val << " ";
    in_Order(root->right);
}
// pre Oreder
void pre_order(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}
// Post Order
void post_Order(Node *root)
{
    if (root == NULL)
        return;
    post_Order(root->left);
    post_Order(root->right);
    cout << root->val << " ";
}
int main()
{
    // Md. Nazmus Sakib
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> v;
    int data;

    while (cin >> data)
    {
        v.emplace_back(data);
    }
    sort(v.begin(), v.end());
    Node *root = convert(v, v.size(), 0, v.size() - 1);
    cout << "print Pre_Order: " << endl;
    pre_order(root);
    cout << endl
         << "Print In_Order: " << endl;
    in_Order(root);
    cout << endl
         << "Print Post_Order: " << endl;
    post_Order(root);
    return 0;
}
