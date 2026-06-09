### 解题思路
遍历root1，查找root2中值为target - node1->val的节点，利用有序性质。

![图片.png](https://pic.leetcode-cn.com/826ef0c4bc262476fd0c78d5546d07409a6b791a066d575be8a2e0ecb4899bc3-%E5%9B%BE%E7%89%87.png)

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
    bool FindVal(TreeNode* root, int val) {
        if (!root) {
            return false;
        }
        if (root->val == val) {
            return true;
        } else if (root->val < val) {
            return FindVal(root->right, val);
        } else {
            return FindVal(root->left, val);
        }
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (!root1 || !root2) {
            return false;
        }
        int part = target - root1->val;
        if (FindVal(root2, part)) {
            return true;
        } else {
            return (twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1->right, root2, target));
        }
    }
};
```