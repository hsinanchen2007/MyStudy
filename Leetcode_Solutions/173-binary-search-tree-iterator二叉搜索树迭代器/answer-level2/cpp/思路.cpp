### 解题思路
也可以先把Tree中序遍历一遍到数组里面，然后找，这样空间消化会比较大一些


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
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
      if(!root) return;

      TreeNode* cur = root;
      while(cur){
        s.push(cur);
        cur = cur->left;
      }
    }
    
    /** @return the next smallest number */
    int next() {
      int res = 0;
      if(!s.empty()){
        TreeNode* cur = s.top();
        res = cur->val;
        s.pop();
        cur = cur->right;
        while(cur){
          s.push(cur);
          cur = cur->left;
        }
      }

      return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
      return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```