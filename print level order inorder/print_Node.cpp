#include <bits/stdc++.h>

using namespace std;
class Node{
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
//Input
Node *input_Node()
{
    int val;
    cin >> val;
    Node *root;
    if(val == -1) root = NULL;
    else root = new Node(val);

    queue <Node *> q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node *p = q.front();
        q.pop();
        //Kaj Jeta amora korbo
        int l, r;
        cin >> l >> r;
        Node *my_Left;
        Node *my_Right;
        if(l == -1) my_Left = NULL;
        else my_Left = new Node(l);
        if(r == -1) my_Right = NULL;
        else my_Right = new Node(r);

        // Cannection
        p->left = my_Left;
        p->right = my_Right;

        //Chield PUSH
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}
//in order
void in_Order(Node *root)
{
    if (root == NULL) return;
    in_Order(root->left);
    cout << root->val << " ";
    in_Order(root->right);
}
//pre Oreder
void pre_order(Node *root)
{
    if(root == NULL) return;
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}
//Post Order
void post_Order(Node *root)
{
    if(root == NULL) return;
    post_Order(root->left);
    post_Order(root->right);
    cout << root->val << " ";
}
int main() 
{
    //Md. Nazmus Sakib
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    Node *root = input_Node();
    cout << "print Pre_Order: " << endl;
    pre_order(root);
    cout << endl << "Print In_Order: " << endl;
    in_Order(root);
    cout << endl << "Print Post_Order: " << endl;
    post_Order(root); 
    return 0;
}
