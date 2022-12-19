### 解题思路
反向中序遍历后存入栈

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<int> s;
    BSTIterator(TreeNode* root) {
        if (root != NULL) {
            inorder(root);
        }
        
    }

    /** @return the next smallest number */
    int next() {
        int x = s.top();
        s.pop();
        return x;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    void inorder(TreeNode* root) {
        if (root->right != NULL) {
            inorder(root->right);
        }
        s.push(root->val);
        if (root->left != NULL) {
            inorder(root->left);
        }
     }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```