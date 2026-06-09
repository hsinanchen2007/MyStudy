### 解题思路
先把树的结点全部入队列，再从队列头部取出。

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
       inOrede(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int tmp = q.front();
        q.pop();
        return tmp;
       
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return q.empty()?false:true;
    }
    void inOrede(TreeNode* root)
    {
        if(root == NULL)
         return ;
         inOrede(root->left);
         q.push(root->val);
         inOrede(root->right);
    }

 private:
  queue<int >q; 
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```