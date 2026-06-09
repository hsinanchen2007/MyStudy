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
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        q.push(root);
        //pre_last指向当前行的最后一个结点,last指向下一行的最后一个结点
        TreeNode* pre_last=root;
        TreeNode* last=root;
        vector<int> temp;
        while(!q.empty()){
            TreeNode* p=q.front();
            temp.push_back(p->val);
            q.pop();
            if(p->left){
                last=p->left;
                q.push(p->left);
            }

            if(p->right){
                last=p->right;
                q.push(p->right);
            }
            //到此行的最末尾处
            if(p==pre_last){
                pre_last=last;
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
```