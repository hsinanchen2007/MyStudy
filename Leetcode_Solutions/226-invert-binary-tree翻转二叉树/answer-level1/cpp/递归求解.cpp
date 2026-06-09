### 解题思路
本题使用递归的方法求解二叉树的翻转。
递归的想法其实还蛮难的。我们需要直到为什么递归。
这个地方明显可以看到inverse操作是进行左右翻转。

那么我们就从宏观的角度来思考这个问题：
翻转后，左右节点发生变换。
左节点应该就是翻转后的右节点。
右节点应该就是翻转后的左节点。

至于翻转的操作是什么暂时不用考虑。
这样的话，我们就可以借着这个逻辑求解这道题了。

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
    //搞个递归就可以了
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;

    }
};
```