### 解题思路
1. 递归把二叉树展开, 什么叫展开呢, 就是左子树的每个节点都只有左子树, 右子树同理. 展开的细节可以看看代码, 画一下图很好理解!
2. 展开后得到一条三角形的二叉树, 用两个指针遍历左右分支, 构造双向链表, 最后左指针是最小, 右指针是最大, 直接相连即可.

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        flatten(root);
        Node* p_left = root;
        Node* p_right = root;
        while (p_left->left) {
            p_left->left->right = p_left;
            p_left = p_left->left;
        }
        while (p_right->right) {
            p_right->right->left = p_right;
            p_right = p_right->right;
        }
        p_left->left = p_right;
        p_right->right = p_left;

        return p_left;
    }

    void flatten(Node* root) {
        if (!root) return;
        Node *p = NULL, *temp = NULL;
        while (root->left && root->left->right) {
            p = root->left->right;
            root->left->right = NULL;
            temp = root->left;
            root->left = p;
            while (p->left) p = p->left;
            p->left = temp;
        }
        while (root->right && root->right->left) {
            p = root->right->left;
            root->right->left = NULL;
            temp = root->right;
            root->right = p;
            while (p->right) p = p->right;
            p->right = temp;
        }

        flatten(root->left);
        flatten(root->right);
    }
};
```