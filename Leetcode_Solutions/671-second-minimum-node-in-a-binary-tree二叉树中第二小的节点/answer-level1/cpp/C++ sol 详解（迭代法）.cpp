### 解题思路

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

//

1. 用迭代实现，中间结果保存在stack中，这里用的是先序遍历。
2. 首先我们将 minVal 初始化成 -1, 当第一次进入循环时 minVal == -1, 因此将 minVal 和 res 均更新成root节点的值。**（需要注意在题设中root的val一定是最小的）**
3. 接着继续迭代，如果发现节点的值比 minVal 大：
   a) minVal == res，则第一次更新res，然后继续迭代。
   b) minVal != res，说明res 之前被更新过一次，但我们要走完O(n)遍历所有节点，以获得最小的res，用 res = min(res, node->val) 就可以轻松获得。
4. 在返回结果前，要确保 minVal != res，否则返回-1。

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
    int findSecondMinimumValue(TreeNode* root) {
        stack<TreeNode*> s({root});

        int minVal = -1; int res = INT_MAX;
        while (!s.empty()) {
            TreeNode* node = s.top(); s.pop();
            if (-1 == minVal) minVal = res = node->val;
            else if (node->val > minVal) {
                if (res == minVal) res = node->val;
                else res = min(res, node->val);
            }

            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }

        return minVal==res? -1 : res;
    }
};
```