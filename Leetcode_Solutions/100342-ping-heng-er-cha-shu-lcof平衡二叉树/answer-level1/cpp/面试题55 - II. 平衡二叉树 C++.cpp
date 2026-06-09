### 解题思路
基本思路：递归判断左右子树的高度差是否大于1。

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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            // 空树
            return true;
        }
        int depth = 0;  // 全局变量，记录树的深度
        return isBalanced(root, depth);
    }
    bool isBalanced(TreeNode* node, int& depth){
        // depth表示该节点到叶节点的深度
        if(node == nullptr){
            depth = 0;
            return true;
        }
        int leftHeight, rightHeight;
        if(isBalanced(node->left, leftHeight) && isBalanced(node->right, rightHeight)){
            // 采用后序遍历，在if()中先求左子树的深度，再求右子树的高度，然后计算该节点的高度
            if(abs(leftHeight - rightHeight) <= 1){
                // 左右高度差应该不大于1
                // depth长度为左右子树最高的加一
                depth = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
                return true;
            }
        }
        return false;
    }
};
```