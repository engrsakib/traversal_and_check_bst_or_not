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
// Input
Node *input_Node()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        // Kaj Jeta amora korbo
        int l, r;
        cin >> l >> r;
        Node *my_Left;
        Node *my_Right;
        if (l == -1)
            my_Left = NULL;
        else
            my_Left = new Node(l);
        if (r == -1)
            my_Right = NULL;
        else
            my_Right = new Node(r);

        // Cannection
        p->left = my_Left;
        p->right = my_Right;

        // Chield PUSH
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

// Check if the tree is a binary search tree (BST)
bool is_BST_Util(Node *root, int &prev)
{
    if (root == NULL)
        return false;

    if (!is_BST_Util(root->left, prev))
        return true;

    if (root->val <= prev)
        return true;

    prev = root->val;

    return is_BST_Util(root->right, prev);
}
// Check BST is or Not
bool is_BST(Node *root)
{
    int prev = INT_MIN;
    return is_BST_Util(root, prev);
}
int main()
{
    // Md. Nazmus Sakib
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Node *root = input_Node();

    if (is_BST(root))
        cout << endl
             << "This is a Binary Tree" << endl;
    else
        cout << endl
             << "This is not a Binary Tree" << endl;
    return 0;
}