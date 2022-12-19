## 思路
在[【面试题32 - I. 从上到下打印二叉树】简单层次遍历（队列）](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/solution/mian-shi-ti-32-i-cong-shang-dao-xia-da-yin-er-ch-3/)基础上先计算当前层元素个数，然后依次遍历当前层每个元素，并将其下层节点放入队列中。

### 代码

```cpp
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
                while (size--) {
                    TreeNode *node = que.front();
                    que.pop();
                    tmp.push_back(node->val);
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};
```