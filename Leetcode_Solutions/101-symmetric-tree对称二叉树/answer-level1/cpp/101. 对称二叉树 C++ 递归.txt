### 解题思路
通过比较先序遍历和先序遍历的对称算法的节点值，判断二叉树是否对称。如果先序遍历和先序遍历的对称算法得到的序列相同，说明二叉树对称。

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
        return isSymmetric(root, root);   
    }
    bool isSymmetric(TreeNode* Lroot, TreeNode* Rroot){
        // 重载isSymmetric
        if(Rroot == nullptr && Lroot == nullptr){
            // 如果左半部分和右半部分都为空，返回true
            return true;
        }
        if(Rroot == nullptr || Lroot == nullptr){
            // 如果只有一部分为空，说明不对称
            return false;
        }
        if(Rroot->val != Lroot->val){
            // 如果当前节点和对称节点值想等，说明这部分对称
            return false;
        }
        return isSymmetric(Lroot->left, Rroot->right) && isSymmetric(Lroot->right, Rroot->left);    // 如果当前节点对称，那么比较左半部分的左子节点与右半部分的右子节点是否对称，左半部分的由子节点和右半部分的左子节点是否对称
    }
};
```