### 解题思路
与求maxDepth思路类似，唯一不同的是要求路径必须以叶节点结束，这就要求当左右子树的较小深度为0时，该深度失效，进而转为另外一非空子树的深度，而无论其大小！

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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int min_depth = 0;
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if(left_depth < right_depth)
        {
             min_depth = left_depth+1;
             if(left_depth == 0)
                min_depth = right_depth+1;
        }
        else
        {
            min_depth = right_depth+1;
            if(right_depth == 0)
                min_depth = left_depth + 1;
        }
        return min_depth;     
    }
};
```