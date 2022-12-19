### 解题思路
1.层序遍历，然后翻转
2.v.insert(v.begin(),tmp);

```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> v(cnt);
            for(int i = 0; i < cnt; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                v[i] = tmp->val;
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
            res.push_back(v);
        }
		//reverse(res.begin(), res.end());
        int n = res.size();
        vector<vector<int>> ans;
        for(int i = n-1; i >= 0; i--) {
            ans.push_back(res[i]);
        }
        return ans;        
    }
};
```
```
vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> v(cnt);
            for(int i = 0; i < cnt; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                v[i] = tmp->val;
                if(tmp->left) {
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
            res.insert(res.begin(),v);
        }
        return res;        
    }
```

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
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()) {
            TreeNode* tmp = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level == res.size()) {
                res.push_back(vector<int>());
            }
            res[level].push_back(tmp->val);
            if(tmp->left) {
                q.push(make_pair(tmp->left,level+1));
            }
            if (tmp->right) {
                q.push(make_pair(tmp->right,level+1));
            }
        }
        reverse(res.begin(), res.end());
        return res;        
    }
};
```