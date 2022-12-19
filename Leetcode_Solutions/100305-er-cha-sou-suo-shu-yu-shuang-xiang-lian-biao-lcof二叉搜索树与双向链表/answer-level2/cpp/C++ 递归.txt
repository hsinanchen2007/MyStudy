### 解题思路
利用递归解决。
先把左子树和右子树变为双向链表后，然后和root节点相连接。
注意点就是，左右子树可能是空的，这个时候需要特别注意。

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
        if (root == NULL) return NULL;
        auto leftList = treeToDoublyList(root->left);
        auto rightList = treeToDoublyList(root->right);
        if (leftList == NULL) {
            leftList = root;
        } else {
            leftList->left->right = root;
            root->left = leftList->left;
        }
        if (rightList == NULL) {
            root->right = leftList;
            leftList->left = root;
        } else {
            root->right = rightList;
            auto t = rightList->left;
            rightList->left = root;
            t->right = leftList;
            leftList->left = t;
            
        }
        return leftList;
    }
};
```