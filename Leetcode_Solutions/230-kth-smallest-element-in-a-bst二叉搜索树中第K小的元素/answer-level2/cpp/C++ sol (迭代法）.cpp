### 解题思路
执行用时 : 16 ms, 在所有 C++ 提交中击败了97.04%的用户

//
1. 使用迭代法来遍历树，注意这是一颗二叉搜索树，因此使用中序遍历的方法就可以从小到大地获取各个数字。
2. 用int count 来计算当前遍历过的节点的个数。当遍历到第k次时，返回其节点对应的值即可。
3. Optional：也可以使用【递归】的解法来做。递归解法比迭代更简单一些。

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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        stack<TreeNode*> s;

        int count = 0;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top(); s.pop();
            if (++count == k) {
                return curr->val;
            }
            curr = curr->right;
        }

        return -1;
    }
};
```