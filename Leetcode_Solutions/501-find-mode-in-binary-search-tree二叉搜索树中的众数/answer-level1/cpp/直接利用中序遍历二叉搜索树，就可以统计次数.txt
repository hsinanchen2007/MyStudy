```
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
    // 方法1：使用map统计次数
    // void midAccess(TreeNode* root, map<int,int>& dict, int& max)
    // {
    //     if(root == NULL) return;
    //     midAccess(root->left,dict,max);
    //     dict[root->val] += 1;
    //     if(dict[root->val] > max)
    //         max = dict[root->val];
    //     midAccess(root->right,dict,max);
    // }
    // vector<int> findMode(TreeNode* root) {
    //     vector<int> res;
    //     map<int,int> dict;
    //     int max = 0;
    //     midAccess(root,dict,max);
    //     for(auto it : dict)
    //     {
    //         if(it.second == max)
    //             res.push_back(it.first);
    //     }
    //     return res;
    // }

    // 方法2：直接利用搜索树统计次数
    void midAccess(TreeNode* root, vector<int>& res, int& curValue, int& curCount, int& maxCount)
    {
        if(root == NULL) return ;
        midAccess(root->left,res,curValue,curCount,maxCount);
        if(root->val == curValue)
        {
            curCount+=1;
        }
        else
        {
            curValue = root->val;
            curCount = 1;
        }

        if(curCount == maxCount)
        {
            res.push_back(curValue);
        }
        else if(curCount > maxCount)
        {
            res.clear();
            res.push_back(curValue);
            maxCount = curCount;
        }
        midAccess(root->right,res,curValue,curCount,maxCount);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        int curValue = root->val, curCount = 0, maxCount = 0;
        midAccess(root,res,curValue,curCount,maxCount);
        return res;
    }
};
```