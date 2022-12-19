### 解题思路
采用队列和中序遍历
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
    queue<int> q;
    BSTIterator(TreeNode* root) {
        inored(root);
    }
    void inored(TreeNode* root){
        if(root == NULL){
            return ;
        }
        inored(root->left);
        q.push(root->val);
        inored(root->right);
    }
    
    /** @return the next smallest number */
    int next() {
        int result = q.front();
        q.pop();
        return result;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```