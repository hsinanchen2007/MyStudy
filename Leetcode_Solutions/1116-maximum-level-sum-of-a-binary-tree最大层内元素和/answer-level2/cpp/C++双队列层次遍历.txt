### 解题思路
1. 层次遍历
2. 因为要返回符合要求的最小层号，所以只在当前层得和严格大于上一层时才更新记录

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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> curQ;
        queue<TreeNode*> nextQ;
        curQ.push(root);
        int res;
        int level = 1;
        int sum = 0;
        int msum = INT_MIN;

        while (!curQ.empty()) {
            TreeNode* p = curQ.front(); curQ.pop();
            sum += p->val;

            if (p->left != nullptr) nextQ.push(p->left);
            if (p->right != nullptr) nextQ.push(p->right);

            if (curQ.empty()) {
                if (sum > msum) {
                    msum = sum;
                    res = level;
                }
                level++;
                sum = 0;
                curQ.swap(nextQ);
            }
        }

        return res;
    }
};
```