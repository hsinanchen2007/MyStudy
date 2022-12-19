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
        vector<vector<int>> vv;

        if(!root){
            return vv;
        }

        vector<int> temp;
        queue<TreeNode*> qu;
        TreeNode* cur;

        int len = 1;
        qu.push(root);

        while(!qu.empty()){
            for(int i = 0; i < len; i++){
                cur = qu.front();
                temp.push_back(cur->val);
                qu.pop();

                if(cur->left){
                    qu.push(cur->left);
                }
                if(cur->right){
                    qu.push(cur->right);
                }
            }
            vv.push_back(temp);
            temp.clear();
            len = qu.size();
        }

        return vv;
    }
};
```