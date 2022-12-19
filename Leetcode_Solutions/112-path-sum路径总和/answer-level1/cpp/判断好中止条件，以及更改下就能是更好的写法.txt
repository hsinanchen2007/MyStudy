### 解题思路
 // 思路：sum减去根节点的值后，看左右子树是否能达到 sum - root.val
 // 那就要思考终止条件是什么呢？因为递归最重要的就是是否能分解成同样的子问题，以及中止条件是啥。
 // 因为这道题有可能 false，有可能true，那么我们就要找到什么情况返回false，什么情况返回true.
 // 因为是根节点到叶子节点的路径，叶子节点即没有子节点，所以加上这个叶子节点的值，才能计算到目标和。

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        } 
        // if(root->left == NULL && root->right == NULL && root->val ==sum)  {
        //     return true;
        // }
        if(root->left == NULL && root->right == NULL)  { // 这种写法比上边的更好一些，因为这种情况下已经可以return， 而不必非要再递归。
            return  root->val ==sum;
        }

        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
```