### 解题思路
C++ 递归

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    void con(Node* l,Node* r){
        Node* lr=l->right;
        if(lr==NULL) return;
        Node* rl=r->left;
        lr->next=rl;
        con(lr,rl);

    }
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        Node* l=root->left;
        if(l==NULL) return root;
        Node* r=root->right;
        l->next=r;
        con(l,r);
        root->left=connect(l);
        root->right=connect(r);
        return root;

    }
};
```