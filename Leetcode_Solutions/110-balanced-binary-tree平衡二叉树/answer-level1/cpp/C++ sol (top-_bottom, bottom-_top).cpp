### 解题思路

1. top -> bottom 的方案很好理解。考虑一下如果计算一棵树的最大深度的问题，那么我们就分left 和 right 两颗子树分别计算他俩的最大深度，如果最大深度差 < 2，则满足需求。这里可以发现，我们需要对每一个树的子树做相同操作，因此这种方法包含大量重复计算，而且结算是自顶向下的。复杂度是 O(nlgn)。
2. bottom -> top 的方案较好的原因是如果某颗子树发现不满足条件了，立即向上放回false结束这一部分的计算，省去了重复计算的部分，复杂度 O(n)。以下解法传入了depth作为引用，你也可以将其作为返回值，如果不满足返回-1就可以了。最终顶上判断结果是否为 -1 也可以达到目的，这样能省一个参数。

Note: 如果已知树不大的情况下，两者耗时差不多，可以使用自顶向下的方法，因为代码简单，也容易想到和理解。

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
class Solution { // bottom -> top, reduce duplication of calculations
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }

    bool isBalanced(TreeNode* node, int& depth) {
        if (!node) return true;

        int left = 0, right = 0;
        bool leftBalanced = isBalanced(node->left, left);
        bool rightBalanced = isBalanced(node->right, right);

        if (leftBalanced && rightBalanced && abs(left-right) < 2) {
            depth = 1 + max(left, right);
            return true;
        }

        return false;
    }
};

// recursive version (top->bottom)
/*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode* node) {
        if (!node) return 0;
        return 1+max(depth(node->left), depth(node->right));
    }
};
*/
```