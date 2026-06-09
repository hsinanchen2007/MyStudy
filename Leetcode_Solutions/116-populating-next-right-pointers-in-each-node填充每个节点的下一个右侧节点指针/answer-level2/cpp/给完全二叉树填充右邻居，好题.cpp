### 解题思路
一开始想定义一个函数，对当前结点的next域进行处理，那么需要当前结点的双亲，判断当前结点是左右孩子是容易的。
但是双亲没想到怎么处理。最后用当前结点的左右孩子的next域进行处理，好处是，不需要有双亲，直接处理，也知道右孩子和左孩子怎么处理。


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
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        root->next=NULL;
        dfs(root);
        return root;
    }
    void dfs(Node* root){
        if(!root) return;
        if(!root->left&&!root->right) return;
        root->left->next=root->right;
        if(root->next==NULL){
            root->right->next=NULL;
        }else{
            root->right->next=root->next->left;
        }
        dfs(root->left);
        dfs(root->right);
        return;
    }
};
```