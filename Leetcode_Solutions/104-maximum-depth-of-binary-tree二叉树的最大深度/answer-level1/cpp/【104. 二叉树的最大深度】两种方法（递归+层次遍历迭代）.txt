## 思路一：递归
### 代码
时间复杂度：O(n)，每个节点访问一次
空间复杂度：O(logn)，树的高度
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};
```

## 思路二：迭代（层次遍历）
### 代码
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;     
        queue<TreeNode*> que;
        que.push(root);
        int toDeleted = 1, next = 0, res = 0;
        while (!que.empty()) {
            TreeNode *p = que.front();
            que.pop();
            if (p->left) {
                que.push(p->left);
                ++next;
            } 
            if (p->right) {
                que.push(p->right);
                ++next;
            } 
            --toDeleted;
            if (toDeleted == 0) {
                toDeleted = next;
                next = 0;                
                ++res;
            }
        }
        return res;
    }
};
```
### 另一种写法
使用队列大小。
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;     
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while (!que.empty()) {
            for (auto i = que.size(); i > 0; --i) {
                TreeNode *p = que.front();
                que.pop();
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            ++res;
        }
        return res;
    }
};
```


