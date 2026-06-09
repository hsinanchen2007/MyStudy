### 解题思路
* [官方思路](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-de-ju-chi-xing-ceng-ci-bian-li-by-leetc/)

### 代码
* bfs实现
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
        if(root == NULL)    return vector<vector<int>>();
        queue<TreeNode*> que;
        deque<int> dq;        // 双向队列暂存数据
        vector<vector<int>> ans;
        bool left2right = true;
        // 层次遍历，用queue存储，每层用NULL分隔开
        que.push(root);
        que.push(NULL);
        while(!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if(node) {
                if(left2right)   dq.push_back(node->val);
                else    dq.push_front(node->val);

                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right); 
            }
            else {
                vector<int> tmp(dq.begin(), dq.end());
                ans.push_back(tmp);
                dq.clear();
                if(!que.empty())    que.push(NULL);
                left2right = !left2right;
            }
        }
        return ans;
    }
};
```

* dfs实现
```cpp
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)    return ans;
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode *node, int level) {
        if(level == ans.size()) {
            vector<int> tmp{node->val};
            ans.push_back(tmp);
        }
        else {
            if(level % 2 == 0) {    // left to right
                ans[level].push_back(node->val);
            }
            else ans[level].insert(ans[level].begin(), node->val);
        }
        if(node->left)  dfs(node->left, level+1);
        if(node->right) dfs(node->right, level+1);
    }
};
```
![1.png](https://pic.leetcode-cn.com/2fbbe9cf3671e8cd9ab5a8e5301a52e00f45e8ba09e14128d974fc2694b75eb3-1.png)
