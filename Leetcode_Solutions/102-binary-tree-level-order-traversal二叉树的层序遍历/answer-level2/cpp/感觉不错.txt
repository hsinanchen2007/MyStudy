### 解题思路


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
        int cnt=0;
        queue<TreeNode *>q;
        vector<vector<int>> ans;
        if(!root)return ans;
        q.push(root);
        cnt=1;
        vector<int>temp;
        while(!q.empty()){
            TreeNode *tempNode=q.front();
            q.pop();cnt--;
            if(tempNode->left)q.push(tempNode->left);
            if(tempNode->right)q.push(tempNode->right);
            if(cnt>0){
                temp.push_back(tempNode->val);
            }else{
                temp.push_back(tempNode->val);
                cnt=q.size();
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
```