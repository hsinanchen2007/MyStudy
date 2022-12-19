### 解题思路
每次连接根节点的两个节点

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
        if(root==NULL || root->left==NULL) return root;
        root->left->next = root->right;   // root左儿子指向右儿子
        if(root->next!=NULL) root->right->next = root->next->left; // root右儿子，如果root的next存在，指向root的next的left    //这里同时处理了最右边的NULL
        connect(root->left);
        connect(root->right);
        return root;
        
    }
};
```