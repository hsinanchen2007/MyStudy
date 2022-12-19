### 解题思路
学会了使用vector.insert(vector.begin())，插在vector的开头

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode *>q;
        q.push(root);
        int cnt=1;
        vector<int>tmp;
        while(!q.empty()){
            TreeNode *temp;
            temp=q.front();
            q.pop();
            cnt--;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            if(cnt>0){
                tmp.push_back(temp->val);
            }else{
                tmp.push_back(temp->val);
                ans.insert(ans.begin(),tmp);
                tmp.clear();
                cnt=q.size();
            }
        }
        return ans;
    }
};
```