## 思路
### 代码
```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            int next = 0, cur = 1;        
            vector<int> tmp;
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                --cur;
                tmp.push_back(node->val);            
                if (node->left) {
                    q.push(node->left);
                    ++next;
                }
                if (node->right) {
                    q.push(node->right);
                    ++next;
                }
                if (cur == 0) {
                    res.push_back(tmp);
                    cur = next;
                    next = 0;
                    tmp.clear();
                }
            }      
        }
        return res;
    }
};
```
### 另一种写法
```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root) {
            queue<TreeNode*> que;
            que.push(root);                                    
            while (!que.empty()) {
                int size = que.size();
                vector<int> tmp;
                TreeNode *q = nullptr;
                for (int i = 0; i < size; ++i) {
                    q = que.front();                    
                    que.pop();
                    tmp.push_back(q->val);
                    if (q->left) que.push(q->left);
                    if (q->right) que.push(q->right);                 
                }
                res.push_back(tmp);
            }      
        }
        return res;
    }
};
```

