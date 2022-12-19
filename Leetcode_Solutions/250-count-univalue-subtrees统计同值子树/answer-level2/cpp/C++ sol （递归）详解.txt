### 解题思路

1. 深度遍历，先探到最底层，NULL时触底反弹（这时肯定时true，没有叶子节点了），递归返回到上一级。
2. 当递归返回到上一级时，判断当前节点的值是否与其left的值相同（当前节点的left存在时），如果不同，返回false。
3. 同理，判断当前节点的值是否与其right的值相同（当前节点的right存在时），如果不同，返回false。
4. 如果2.3.都没有返回false，说明满足题设条件，这时再判断 left 和 right 是否都为 true，如果是，那么res++。

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
    int countUnivalSubtrees(TreeNode* root) { // 后序遍历的题目
        if (!root) return 0;

        int res = 0;
        countUnivalSubtrees(root, res);

        return res;
    }

    bool countUnivalSubtrees(TreeNode* node, int& res) {
        if (!node) return true;
        
        bool left = countUnivalSubtrees(node->left, res);
        bool right = countUnivalSubtrees(node->right, res);
        if (node->left && node->left->val != node->val) return false;
        if (node->right && node->right->val != node->val) return false;

        if (left && right) res++;
        return true;
    }
};
```