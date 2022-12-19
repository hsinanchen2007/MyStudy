### 解题思路
只需要比常规层序遍历增加一个当前遍历层次即可，当times为奇数时，不需要翻转数组tem_res，
偶数时，翻转数组tem_res即可
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>tem;
        vector<vector<int>>res;
        if(root==NULL)return res;
        tem.push(root);
        int times=1;
        while(!tem.empty())
        {
            vector<int>res_tem;
            int l=tem.size();
            for(int i=0;i<l;i++)
            {
                TreeNode* tem_node=tem.front();
                res_tem.push_back(tem_node->val);
                if(tem_node->left)tem.push(tem_node->left);
                if(tem_node->right)tem.push(tem_node->right);
                tem.pop();
            }
            if(times%2==0)reverse(res_tem.begin(),res_tem.end());
            res.push_back(res_tem);
            times++;
        }
        return res;
    }
};
```