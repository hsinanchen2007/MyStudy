### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/7a5b28099ab66a2acb0478dc1ac8ff05494c7ea82682de8a575e723cde0ec882-image.png)

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
        if(!root) return {}; 
        vector<vector<int>>res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            vector<int> temp;
            int x = q.size();
            for(int i = 0; i < x; i++){
                TreeNode* node = q.front(); q.pop();
                temp.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(flag){
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
            }else{
                res.push_back(temp);    
            }
            flag = !flag;
        }
        return res;
    }
};
```