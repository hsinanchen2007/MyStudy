## 解法：

对于二叉树的相关题目，一般来说都可以转换为求解左右子树的问题。

那么，对于该题目，就需要我们弄明白二叉树与其左右子树的直径的关系。既然，二叉树的直径指的是任意两个节点之间路径的最大值。那么，这两个节点可能都位于左子树，也可能都位于右子树，也可能一个在左子树，一个在右子树。

对于都位于左子树和右子树的情况，可以采用递归的方式求解；而对于一个位于左子树，一个位于右子树的情况，要想让这两个节点之间的路径最长，那么这两个节点肯定分别位于左右子树的叶子节点处，且这两个叶子节点在各自的树中具有最大的深度。

那么，在程序中就需要求出如下三个值：

* 左子树的直径（递归）；
* 右子树的直径（递归）；
* 左子树的深度和右子树的深度。

求出了上述三个值后，当前二叉树的直径就等于：
$$
D(root)=Max(D(left), D(right),depth(left)+depth(right)+2)
$$
至于为何第三个元素是左子树的深度+右子树的深度+2，是因为在将左子树和右子树连接到当前根节点上时，会需要额外的两条边，而这两条边会增加路径的长度。

在代码的具体实现时，采用后序遍历的方式。

代码如下：

```c++
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int depth = 0;
        int diameter = 0;
        diameterOfBinaryTreeCore(root, depth, diameter);
        return diameter;
    }

    // depth: 保存当前子树的深度， diameter：保存当前子树的直径
    void diameterOfBinaryTreeCore(TreeNode* root, int& depth, int& diameter){
        // 叶子节点的深度和直径都为0
        if (root->left == nullptr && root->right == nullptr){
            depth = 0;
            diameter = 0;
            return;
        }

        int left_depth = -1;
        int left_diameter = 0;
        if (root->left != nullptr){
            diameterOfBinaryTreeCore(root->left, left_depth, left_diameter);
        }
        int right_depth = -1;
        int right_diameter = 0;
        if (root->right != nullptr){
            diameterOfBinaryTreeCore(root->right, right_depth, right_diameter);
        }
        
        // 当前子树的直径等于 左子树的直径、右子树的直径 和 左子树深度+右子树深度 之间的最大值
        diameter = max(max(left_diameter, right_diameter), left_depth + right_depth + 2);
        // 当前子树的深度等于 左右子树中的最大深度加1
        depth = max(left_depth, right_depth) + 1;
    }
};
```