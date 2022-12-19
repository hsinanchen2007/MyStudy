### 解题思路
1. 递归计算左子树和右子树的深度。
   - 最终结果为左右子树中最大的深度+1
   - 考虑好递归思路！然后+1放在最后，开始是节点为空判断的返回！
2. 思路2：层序遍历，计数！

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
    int maxDepth(TreeNode* root) {
        if(root==NULL)  return 0;  //递归返回的条件判断
        return max(maxDepth(root->left),maxDepth(root->right))+1; //每次就只有一个+1，放在这里
    }

};
```