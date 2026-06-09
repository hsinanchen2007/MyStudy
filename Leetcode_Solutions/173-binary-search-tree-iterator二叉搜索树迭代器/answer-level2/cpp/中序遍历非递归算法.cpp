### 解题思路
此处撰写解题思路

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
    BSTIterator(TreeNode* root) {
        TreeNode* p = root;
        while (p) {
            s.push(p);
            p = p->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = s.top(); 
        int ret = node->val;
        s.pop();

        TreeNode* p = node->right;
        while (p) {
            s.push(p);
            p = p->left;
        }

        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```