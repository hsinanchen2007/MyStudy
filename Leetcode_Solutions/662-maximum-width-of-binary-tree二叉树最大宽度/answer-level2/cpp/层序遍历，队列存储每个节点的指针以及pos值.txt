### 解题思路
队列中保存每个节点的指针以及pos值，左右孩子的pos分别是2*pos和2*pos+1，每层的宽度为队尾pos-队首pos+1

### 代码

```cpp
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        int ans = 1;
        q.push({root, 1});
        while (!q.empty()) {
            int sz = q.size();
            ans = max(int(q.back().second - q.front().second + 1), ans);
            for (int i=0; i < sz; i++) {
                TreeNode *node = q.front().first;
                unsigned long long pos = q.front().second;
                q.pop();
                if (node->left) q.push({node->left, 2 * pos});
                if (node->right) q.push({node->right, 2 * pos + 1});
            }
        }
        return ans;
    }
};
```
执行用时 :4 ms, 在所有 C++ 提交中击败了96.73%的用户
内存消耗 :15.3 MB, 在所有 C++ 提交中击败了88.41%的用户