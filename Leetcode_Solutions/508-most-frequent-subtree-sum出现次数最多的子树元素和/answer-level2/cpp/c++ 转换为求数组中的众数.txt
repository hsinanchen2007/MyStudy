### 解题思路
递归求解出每个节点的值，放于一个vector中，转换为求数组中的众数

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        vector<int> r;
        if(root==NULL)
            return res; 
        help(root,res);
        if(res.size()==1)
            return res;
        int cur=1,max=1;
        sort(res.begin(),res.end());
        for(int i=1;i<res.size();i++)
        {
            if(i==1&&res[0]!=res[1])
                r.push_back(res[0]);
            cur=(res[i]==res[i-1])?cur+1:1;
            if(cur==max)
                r.push_back(res[i]);
            if(cur>max)
            {
                r.clear();
                r.push_back(res[i]);
                max=cur;
            }
        }
        return r;
    }
    int help(TreeNode* root, vector<int>& res)
    {
        if(!root)
            return 0;
        int left=help(root->left,res);
        int right=help(root->right,res);
        if(root->left==NULL&&root->right==NULL)
        {
             res.push_back(root->val);
             return root->val;
        }
        root->val=root->val+left+right;
        res.push_back(root->val);
        return root->val;
    }
};
```