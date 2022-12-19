自顶向下遍历，判断当前是否是叶结点并满足总和等于sum，若满足，将vector<int>插入到vector<vector<int>>
中，若不满足，继续递归，直到节点为空，此时什么都不做，返回

注意：只要当前节点不为空，我们便将结点插入到vector<int>中

代码是pass-by-value，所以相对比较耗时，用时20ms，消耗内存37.7mb

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vec1;
        vector<int>vec2;
        solve(root,vec1,vec2,sum);
        return vec1;
    }
    void solve(TreeNode *root,vector<vector<int>> &total,vector<int>thisTotal,int sum)
    {
        if(!root)
            return;
        sum-=root->val;
        thisTotal.push_back(root->val);
        if(!root->left&&!root->right&&sum==0)
            total.push_back(thisTotal);
        solve(root->left,total,thisTotal,sum);
        solve(root->right,total,thisTotal,sum);
    }
};
```