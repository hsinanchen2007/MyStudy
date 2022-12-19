### 思路一：队列+栈
将正常层次遍历的每层结果放入一个栈中，最后再将栈中结果取出放入结果集。

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
        if (root == nullptr) return res;
        queue<TreeNode*> que;
        stack<vector<int>> st;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode *q = que.front();
                que.pop();
                tmp.push_back(q->val);
                if (q->left) que.push(q->left);
                if (q->right) que.push(q->right);
            }
            st.push(tmp);
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
```

### 思路二：头插法

### 代码
```c++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> que;        
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode *q = que.front();
                que.pop();
                tmp.push_back(q->val);
                if (q->left) que.push(q->left);
                if (q->right) que.push(q->right);
            }
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};
```

### 思路三：逆序法

### 代码
```c++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> que;        
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode *q = que.front();
                que.pop();
                tmp.push_back(q->val);
                if (q->left) que.push(q->left);
                if (q->right) que.push(q->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```


