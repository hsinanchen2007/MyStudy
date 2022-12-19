### 解题思路
使用队列完成广大优先搜索，进而完成层次遍历

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
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n>0){
                TreeNode* now=q.front();
                temp.push_back(now->val);
                q.pop();
                if(now->left!=NULL)
                    q.push(now->left);
                if(now->right!=NULL)
                    q.push(now->right);
                n--;
            }
            res.push_back(temp);
        }
        return res;
    }
};
```