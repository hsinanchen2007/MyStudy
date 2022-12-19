## 思路
在[【面试题32 - II. 从上到下打印二叉树 II】简单层次遍历（队列）](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/solution/mian-shi-ti-32-ii-cong-shang-dao-xia-da-yin-er-c-4/)基础上偶数层逆序即可。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root) {
            queue<TreeNode*> que;
            que.push(root);
            int line = 1;
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
                if (line % 2 == 0) {
                    reverse(tmp.begin(), tmp.end()); //偶数层逆序
                }
                res.push_back(tmp);
                ++line;
            }
        }
        return res;
    }
};
```