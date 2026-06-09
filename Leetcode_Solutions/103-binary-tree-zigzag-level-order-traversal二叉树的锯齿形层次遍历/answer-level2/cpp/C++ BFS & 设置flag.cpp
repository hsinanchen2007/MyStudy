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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ret;
         // 根节点为空
         if(!root) return ret;
         vector<int> level_vec;
         bool isReverse = false;
         queue<TreeNode*> q;
         q.push(root);
         // 层序遍历
         while(!q.empty()){
             int size = q.size();
             level_vec.clear();
             while(size--){
                 TreeNode* tmp = q.front();
                 q.pop();
                 level_vec.push_back(tmp->val);
                 if(tmp->left) q.push(tmp->left);
                 if(tmp->right) q.push(tmp->right);
             }
             // 反转
             if(isReverse){
                 reverse(begin(level_vec),end(level_vec));
             }
             ret.push_back(level_vec);
             isReverse = !isReverse;
         }
         return ret;
    }
};
```