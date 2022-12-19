### 解题思路
深度优先思想

从根节点开始递归查找：
若当前为空说明上一级是叶子结点，不进行层数增加，返回0；
若当前左（右）子树为空，则说明上一级结点只有一个子树，那么为空的停止计数，转向不为空方向继续计数。
若当前左右子树都不为空，分别计算左右子树的深度，选最小返回。

循环结束时，所有结点都被遍历，左右子树高度得出，返回左右子树中较小的值为最小高度。



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
    int minDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        if (root->left == NULL) return minDepth(root->right)+1;
        if (root->right == NULL) return minDepth(root->left)+1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
```