第一个想到的解法是自底向上的解法，递归到符合条件的叶子节点后，然后沿着回溯路径一路insert，但是这样因为insert会导致大量的数据移动，所以复杂度较高
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root)return res;
        if(root->val==sum&&!root->left&&!root->right){
            vector<int> the_last;
            the_last.push_back(root->val);
            res.push_back(the_last);
        }
        else{
            vector<vector<int>> mid;
            mid=pathSum(root->left,sum-root->val);
            for(auto s:mid){
                s.insert(s.begin(),root->val);
                res.push_back(s);
            }
            mid=pathSum(root->right,sum-root->val);
            for(auto s:mid){
                s.insert(s.begin(),root->val);
                res.push_back(s);
            }
        }
        return res;
    }
};
```

然后想到的是设置一个辅助的helper，记录路径上的节点，遇到符合条件的就res.push_back(helper)，这样就显著的降低了时间复杂度
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
    vector<int> helper;
    vector<vector<int>> res;
    void pathsum(TreeNode* root, int sum){
        if(!root)return;
        if(root->val==sum&&!root->left&&!root->right){
            res.push_back(helper);
            res[res.size()-1].push_back(sum);
        }
        else{
            helper.push_back(root->val);
            pathsum(root->left,sum-root->val);
            helper.pop_back();
            helper.push_back(root->val);
            pathsum(root->right,sum-root->val);
            helper.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pathsum(root,sum);
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/e8279ed23a98864bcb6bbfa72ac40f95d874dc77f9a7cf023ad7bda4d4b154d3-image.png)



