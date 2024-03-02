<h2>Project Name:</h2><h3> Traversal a tree and check is BST or not
not.</h3>

<h2>Background Study</h2>

<p>A binary search tree is a method to organize data, together with operations on these data (i.e., it is a data structure). In particular, the operation that this organization wants to perform really fast is searching. The data are records that may contain many fields, but one field is specifically used for ordering the data records; this field is called the record Node. In order to simplify things, from now on we will assume that the data record contains only this Node, and the Nodes are integers; but we don't require that Nodes are unique (so, the same Node may show up multiple times). Then a binary search tree consists of nodes that are of the following form:</p>

<h2>[Node, Left subtree, Right subtree]</h2>

<p>Notice that a node is itself a record. It is a list with three elements: the first element is an integer (key), and the next two elements are themselves binary search trees, a Left subtree and a Right subtree!
So the definition of a binary search tree is a recursive one. Before we define binary search trees though, it is simpler to first define binary trees (without the “search” component)</p>

<p>We can draw a binary tree using “nodes” to hold the keys and lines (edges) that show what are the left and right subtrees of the “nodes”. Here is such a conceptual drawing of two binary trees.</p>

<img src="./print level order inorder/pic/binary-tree-to-DLL.png">

<h2>Tree Traversal</h2>
<p>Traversing a tree means visiting every node in the tree. You might, for instance, want to add all the values in the tree or find the largest one. For all these operations, you will need to visit each node of the tree.

Linear data structures like arrays, stacks, queues, and linked list have only one way to read the data. But a hierarchical data structure like a tree can be traversed in different ways.</p>

```
1. Depth First Search or DFS
    Inorder Traversal
    Preorder Traversal
    Postorder Traversal
2. Level Order Traversal or Breadth First Search or  BFS
    Boundary Traversal
    Diagonal Traversal
```

<img src="./print level order inorder/pic/TreeTraversal.png" title="Stack Image->Sakib" >

<h2>Operation Details</h2>

<h3>Inorder traversal</h3>
<p>
1. First, visit all the nodes in the left subtree<br>
2. Then the root node<br>
3. Visit all the nodes in the right subtree<br>
</p>

```
inorder(root->left)
display(root->data)
inorder(root->right)
```

<img src="./print level order inorder/pic/f inOrder traversal.jpg" title="Stack Image->Sakib" >

<h3>Preorder traversal</h3>
<p>
1. Visit root node<br>
2. Visit all the nodes in the left subtree<br>
3. Visit all the nodes in the right subtree
</p>

```
display(root->data)
preorder(root->left)
preorder(root->right)
```

<img src="./print level order inorder/pic/preorder Traversal.jpg" title="Stack Image->Sakib" >

<h3>Postorder traversal</h3>
<p>
1. Visit all the nodes in the left subtree<br>
2. Visit all the nodes in the right subtree<br>
3. Visit the root node
</p>

```
display(root->data)
preorder(root->left)
preorder(root->right)
```

<img src="./print level order inorder/pic/postOrder-f.jpg" title="Stack Image->Sakib" >

<h2>Source Code </h2>

<b> <a href="./print level order inorder/print_and_check_bst.cpp">Code File </a>

```cpp
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
```

<h2>Binary Search Tree(BST)</h2>

<p>Binary search tree is a data structure that quickly allows us to maintain a sorted list of numbers.</p>
<p>
    <li> It is called a binary tree because each tree node has a maximum of two children.<br></li>
    <li> It is called a search tree because it can be used to search for the presence of a number in <b><i>O(log(n))</i></b> time.</li>
</p>
<p>
The properties that separate a binary search tree from a regular binary tree is

<li>All nodes of left subtree are less than the root node
<li>All nodes of right subtree are more than the root node
<li>Both subtrees of each node are also BSTs i.e. they have the above two properties
</p>

<img src="./print level order inorder/pic/bst-vs-not-bst.webp">

<h2>Search Operation</h2>

<p>
The algorithm depends on the property of BST that if each left subtree has values below root and each right subtree has values above the root.

If the value is below the root, we can say for sure that the value is not in the right subtree; we need to only search in the left subtree and if the value is above the root, we can say for sure that the value is not in the left subtree; we need to only search in the right subtree.

</p>

<h2> code</h2>

<a href="./print level order inorder/print_and_check_bst.cpp">Traversal and Check BST or Not ?</a>

```cpp
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
// Check if the tree is a binary search tree (BST)
bool is_BST_Util(Node *root, int &prev) {
    if (root == NULL)
        return true;

    if (!is_BST_Util(root->left, prev))
        return false;

    if (root->val <= prev)
        return false;

    prev = root->val;

    return is_BST_Util(root->right, prev);
}
//Check BST is or Not
bool is_BST(Node *root) {
    int prev = INT_MIN;
    return is_BST_Util(root, prev);
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
    cout << endl;
    if(!is_BST(root)) cout << "\nThis is a Binary Tree" << endl;
    else cout << "\nThis is not a Binary Tree" << endl;
    return 0;
}
```
<h2>Binary Search Tree Complexities</h2>
<img src="./print level order inorder/pic/Capture.PNG">



| Name             | Link                          |
| ---------------- | ----------------------------- |
| Md. Nazmus Sakib | BSc In Engr.                  |
| Email            | engrsakib02@gmail.com         |
| LinkedIn       | [LinkedIn][linked_in_link] |
| Facebook         | [Facebook][facebook_link]     |
| Code Force       | [Code Force][Code_force_link] |
| CodeChef         | [CodeChef][CodeChef_link]     |
| LeetCode      | [Code Force][LeetCode_link] |

[linked_in_link]: https://www.linkedin.com/in/engrsakib/
[facebook_link]: https://www.facebook.com/engrsakib02/
[code_force_link]: https://codeforces.com/profile/engrsakib
[LeetCode_link]: https://leetcode.com/engrsakib/
[CodeChef_link]: https://www.codechef.com/users/engrsakib
