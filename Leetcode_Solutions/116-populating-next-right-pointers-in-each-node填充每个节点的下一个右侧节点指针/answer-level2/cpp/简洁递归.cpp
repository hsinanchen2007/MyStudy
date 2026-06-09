### 解题思路
本题其实是将一个普通的树转化为了B树，方法在于对每个节点增加平级链接，主要有两个逻辑点：
1. 左儿子连接右儿子
2. 右儿子连接父亲的next的左儿子
根据这两点写代码即可

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
        if (root == NULL)
            return NULL;
        root->next = NULL;
        connectRight(root, root);
        return root;
    }

    void connectRight(Node *root, Node *paraent)
    {
        if (root == NULL)
            return;       
        if (root == paraent->left)
            root->next = paraent->right;
        else if (paraent->next != NULL)
            root->next = paraent->next->left;
        connectRight(root->left, root);
        connectRight(root->right, root);
    }
};
```