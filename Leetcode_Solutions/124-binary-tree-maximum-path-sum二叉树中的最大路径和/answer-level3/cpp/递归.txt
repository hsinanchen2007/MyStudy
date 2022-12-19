### 解题思路
在递归函数中，如果当前结点不存在，那么直接返回0。否则就分别对其左右子节点调用递归函数，由于路径和有可能为负数，而我们当然不希望加上负的路径和，所以我们和0相比，取较大的那个，就是要么不加，加就要加正数。然后我们来更新全局最大值结果res，就是以左子结点为终点的最大path之和加上以右子结点为终点的最大path之和，还要加上当前结点值，这样就组成了一个条完整的路径。

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
    
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        maxPath(root);
        return res;
    }
private:
    int res;
    int maxPath(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = max(0,maxPath(root->left));
        int right = max(0, maxPath(root->right));
        res = max(res, left+right+root->val);
        return max(left,right)+root->val;
    }
};
```