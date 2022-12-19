## 思路一：递归


### 代码
时间复杂度：O(n)，每个节点访问一次
空间复杂度：O(n)，树的高度
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (root) {
            if (!root->left && !root->right) return 1;
            res = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
        return res;
    }
};
```
### 继续简化
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 +  max(maxDepth(root->left), maxDepth(root->right));
    }
};
```


## 思路二：非递归层次遍历

### 代码
时间复杂度：O(n)，每个节点访问一次
空间复杂度：O(n)，树的最大宽度
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;        
        if (root) {
            queue<TreeNode*> que;
            que.push(root);
            while (!que.empty()) {
                for (int i = que.size(); i > 0; --i) {
                    TreeNode *node = que.front();
                    que.pop();
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);                    
                }
                ++res;
            }
        }
        return res;
    }
};
```
