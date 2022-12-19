### 解题思路
思路很简单，postorder遍历下树，每个节点比较下左右子树高度。
只是写的时候又踩坑了，如果只有一棵子树，最小值只能是那颗子树的高度，因为它并不是叶子结点。
最尴尬的是题目的note:A leaf node is a node with no children.

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
//f用来计算每棵树的高度
//有坑：要注意只有一颗子树（子结点）的结点不是叶子节点
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if(root->left == NULL)
           return rightDepth + 1;
        else if(root->right == NULL)
            return leftDepth + 1;
        return min(leftDepth,rightDepth) + 1;
    }
};
```