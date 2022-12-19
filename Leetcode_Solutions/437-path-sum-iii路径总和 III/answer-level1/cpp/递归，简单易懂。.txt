### 解题思路
递归时保存每一层的前缀和，每次弹出前判断和是否为目标值
![捕获.PNG](https://pic.leetcode-cn.com/c3ad7bb278358b10d7422356d4c3543454f42cd579f8ac117c4d02b86e35a417-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        vector<int>prefixSum(1, 0);
        int count = 0;
        helperCountPathSum(root, sum, prefixSum, count);
        return count;
    }
    void helperCountPathSum(TreeNode* node, int& sum, vector<int>& prefixSum, int& count) {
        prefixSum.push_back(prefixSum.back() + node->val);
        if (node->left)
            helperCountPathSum(node->left, sum, prefixSum, count);
        if (node->right)
            helperCountPathSum(node->right, sum, prefixSum, count);
        int back = prefixSum.back(); 
        for (int i = prefixSum.size() - 2; i >= 0; i--)
            if (back - prefixSum[i] == sum) count++;
        prefixSum.pop_back();
    }
};
```