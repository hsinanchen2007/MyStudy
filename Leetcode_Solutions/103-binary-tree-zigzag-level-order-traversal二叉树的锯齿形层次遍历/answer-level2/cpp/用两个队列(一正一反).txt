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
    //q1记录正序，q2记录反序
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        q1.push(root);
        q2.push(root);
        TreeNode* pre_last1=root;
        TreeNode* last1=root;
        TreeNode* pre_last2=root;
        TreeNode* last2=root;
        int level=0;
        vector<int> temp;
        while(!q1.empty()&&!q2.empty()){
            TreeNode* p1=q1.front();
            q1.pop();
            TreeNode* p2=q2.front();
            q2.pop();
            if(p1->left){
                last1=p1->left;
                q1.push(p1->left);
            }
            if(p1->right){
                last1=p1->right;
                q1.push(p1->right);
            }
            if(p2->right){
                last2=p2->right;
                q2.push(p2->right);
            }
            if(p2->left){
                last2=p2->left;
                q2.push(p2->left);
            }
            if(level==0) temp.push_back(p1->val);
            else temp.push_back(p2->val);
            //两个同时到达当前行的最后一个
            if(p1==pre_last1){
                pre_last1=last1;
                pre_last2=last2;
                if(level==0){
                    ans.push_back(temp);
                    temp.clear();
                    level=1;
                }
                else{
                    ans.push_back(temp);
                    temp.clear();
                    level=1-level;
                }
            }
        }
        return ans;
    }
};
```