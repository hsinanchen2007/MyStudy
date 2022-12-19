### 解题思路
遍历树，值放到数组里，排序，返回最小值
![LSC$BG1UM2LU1(SV1}KJ$QQ.png](https://pic.leetcode-cn.com/cd3ad2d5d6709813a3c6a7f48c5158ad4fdfcea0480472245a750338a72c24b0-LSC$BG1UM2LU1\(SV1%7DKJ$QQ.png)

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
    int minDiffInBST(TreeNode* root) {
        vector<int> num;
        dfs(root,num);
        sort(num.begin(),num.end());
        int min=num[1]-num[0];
        for(int i=1;i<num.size();i++)
            min<=num[i]-num[i-1]?:min=num[i]-num[i-1];
        return min;
    }
    void dfs(TreeNode* t,vector<int>& n)
    {
        if(!t) 
            return;
        n.push_back(t->val);
        dfs(t->left,n);
        dfs(t->right,n);
    }
};
```