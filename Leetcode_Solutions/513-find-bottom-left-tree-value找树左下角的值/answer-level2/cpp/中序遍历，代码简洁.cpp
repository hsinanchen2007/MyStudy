### 解题思路
中序遍历，使用一个全局遍量记录最大深度，当到达的深度大于目前的最大深度时，为第一次到达该最大深度，更新结果，不超过该深度时，均不会更新

### 复杂度
时间复杂度：每个结点访问一次，$O(n)$
空间复杂度：不计算调栈，$O(1)$；计算调栈$O(h)$，`h`为最大深度

### 代码

```cpp
class Solution {
public:
    int res = 0;
    int maxlevel = 0;
    int findBottomLeftValue(TreeNode* root) {
        helper(root, 1);
        return res;
    }

    void helper(TreeNode* root, int level){
        if(root == NULL) return;

        helper(root->left, level + 1);

        if(level > maxlevel){
            maxlevel = level;
            res = root->val;
        }

        helper(root->right, level + 1);
    }
};
```