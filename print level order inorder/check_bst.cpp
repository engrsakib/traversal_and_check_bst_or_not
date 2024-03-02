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
vector<int> vv;
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
// Check if the tree is a binary search tree (BST)
// Check BST is or Not
bool is_BST(Node *root)
{
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = i + 1; j < vv.size() - 1; j++)
        {
            if (vv[i] > vv[j])
                return false;
        }
    }
    return true;
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
    // sort(v.begin(), v.end());
    Node *root = convert(v, v.size(), 0, v.size() - 1);

    if (is_BST(root))
        cout << endl
             << endl
             << "This is a Binary Search Tree" << endl;
    else
        cout << endl
             << endl
             << "This is not a Binary Search Tree" << endl;
    return 0;
}
