### 解题思路
递归   （关注微信公众号'码农黑板报'获取更多题解）
![image.png](https://pic.leetcode-cn.com/2ff01a8341350f0ee85ffa4390d831a8f83745d406499f190566765e52187552-image.png)


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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return equalJudge(root->left, root->right);
    }

    bool equalJudge(TreeNode* node1, TreeNode* node2) {
        if (node1 == NULL && node2 == NULL) {
            return true;
        }
        if (node1 && node2 == NULL) {
            return false;
        }
        if (node1 == NULL && node2) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return equalJudge(node1->left, node2->right) &&
                equalJudge(node1->right, node2->left);
    }
};
```