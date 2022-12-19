### 解题思路
BFS到达第一个无子节点的节点即可
### 代码

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (NULL == root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 1;
        while (!que.empty()) {
            int i=que.size();
            while (i>0) {
                TreeNode* node = que.front();
                que.pop();
                if (NULL != node) {
                    if (NULL==node->left && NULL==node->right) return depth;
                    que.push(node->left);
                    que.push(node->right);
                }
                i--;
            }
            depth++;
        }
        return -1;
    }
};
```