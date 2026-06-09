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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> que;
        stack<TreeNode*> sta;
        que.push(root);
        int count=1;
        vector<int> result;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;++i){
                if(count%2!=0){
                    TreeNode *temp=que.front();
                    result.push_back(temp->val);
                    if(temp->left) sta.push(temp->left);
                    if(temp->right) sta.push(temp->right);
                    que.pop();
                }
                else{
                    TreeNode* temp=que.front();
                    result.push_back(temp->val);
                    if(temp->right) sta.push(temp->right);
                    if(temp->left) sta.push(temp->left);
                    que.pop();
                }
            }
            ans.push_back(result);
            result.clear();
            count++;
            while(!sta.empty()){
                TreeNode *temp=sta.top();
                que.push(temp);
                sta.pop();
            }
        }
        return ans;
    }
};
```