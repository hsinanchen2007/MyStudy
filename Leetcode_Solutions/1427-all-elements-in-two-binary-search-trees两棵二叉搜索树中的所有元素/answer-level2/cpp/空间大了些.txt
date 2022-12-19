### 解题思路
此处撰写解题思路

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        inorder(root1,ans1);
        inorder(root2,ans2);
        vector<int> ans;
        int i,j;
        for(i=0,j=0;i<ans1.size()&&j<ans2.size();){
            if(ans1[i]<=ans2[j]){
                ans.push_back(ans1[i]);
                i++;
            }
            else{
                ans.push_back(ans2[j]);
                j++;
            }
        }
        for(;i<ans1.size();i++){
            ans.push_back(ans1[i]);
        }
        for(;j<ans2.size();j++){
            ans.push_back(ans2[j]);
        }
        return ans;
    }
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root)return;
        if(root->left){
            inorder(root->left,ans);
        }
        ans.push_back(root->val);
        if(root->right){
            inorder(root->right,ans);
        }
    }
};
```