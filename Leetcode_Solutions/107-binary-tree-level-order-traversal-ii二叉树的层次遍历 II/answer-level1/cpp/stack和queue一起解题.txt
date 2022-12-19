### 解题思路
观察题目，发现我们只是更改了输出顺序，因此直接使用stack存储并输出就可完成要求。
注意判断root是否为空。

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
        TreeNode*p=root;
        queue<TreeNode*>Q;
        vector<vector<int>>v;
        stack<vector<int>>s;
        Q.push(root);
        while(!Q.empty()){
            vector<int>v1;
            for(int i=Q.size();i>0;i--){
                p=Q.front();Q.pop();
                v1.push_back(p->val);
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
            s.push(v1);
        }
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
```