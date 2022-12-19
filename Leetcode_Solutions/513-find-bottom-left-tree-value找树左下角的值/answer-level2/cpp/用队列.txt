### 解题思路
从右到左加入队列，队列最后一个元素就是最后一层最左边的元素

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
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        //从右往左加入队列
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;
        while(!q.empty())
        {
            t = q.front();
            if(t->right!=NULL)q.push(t->right);
            if(t->left!=NULL)q.push(t->left);
            q.pop();
        }
        return t->val;
    }
};
```