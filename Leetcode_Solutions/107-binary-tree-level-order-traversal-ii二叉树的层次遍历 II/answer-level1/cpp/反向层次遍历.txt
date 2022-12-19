### 解题思路
其实用了一个trick，类似于后序遍历是反向存储的先序遍历，反向层次遍历也就是反向存储的正向层次遍历

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
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            for(int i = q.size();i>0;--i){
                TreeNode* p = q.front();q.pop();
                temp.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            res.insert(res.begin(),temp);
        }
        return res;
    }
};
```