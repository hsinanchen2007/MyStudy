### 解题思路
很正常的层次遍历bfs，如果可以优化的话就是在判断语气那里可以剪枝，但这题好像剪不了枝
queue的元素为pair，保存node指针和当前值

那么问题反而在于怎么保存路径
使用map<TreeNode*, TreeNode*> 32 ms, 在所有 C++ 提交中击败了17.36%的用户（被吊起来打
显然我们不需要有序关联容器浪费时间去做比较
使用unorder_map<TreeNode*, TreeNode*>8 ms, 在所有 C++ 提交中击败了93.92%的用户

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vv;
        if(root == NULL) return vv;
        vector<TreeNode*> v;
        queue<pair<TreeNode*, int> > q;
        unordered_map<TreeNode*, TreeNode*> m;
        q.push({root, sum});
        while(!q.empty()){
            pair p = q.front(); q.pop();
            TreeNode* tmp = p.first;
            int num = p.second;
            if(tmp->left != NULL){
                q.push({tmp->left, num-tmp->val});
                 m[tmp->left] = tmp;
            }
            if(tmp->right != NULL){
                q.push({tmp->right, num-tmp->val});
                m[tmp->right] = tmp;
            }
            if(tmp->left == NULL && tmp->right == NULL && num == tmp->val){
                v.push_back(tmp);
            }
        }
        vector<int> ans;
        for(int i = 0; i < v.size(); ++i){
            TreeNode* tmp = v[i];
            while(tmp){
                ans.push_back(tmp->val);
                tmp = m[tmp];
            }
            reverse(ans.begin(), ans.end());
            vv.push_back(ans);
            ans.clear();
        }
        return vv;
    }
};