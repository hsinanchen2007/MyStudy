### 解题思路
1）递归求解每个节点的高度，关键在于父节点和子节点的高度值之间的关系；
2）计算平衡因子；
3）计算平衡性，使用递归求解每一个节点的平衡因子；
> 如果缺少最后的递归左右子树，就会导致只计算了根节点的平衡因子，其他节点的平衡因子都没有计算。

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
    int getHeight(TreeNode * node){
        if(node== nullptr)
            return 0;
        return 1+std::max(getHeight(node->left),getHeight(node->right));
    }

    int getBalanceFactor(TreeNode* node){
        if(node==nullptr)
            return 0;
        return getHeight(node->left)-getHeight(node->right);
    }

    bool isBalanced(TreeNode* root) {
        if(root== nullptr)
            return true;
        int balanceFactor=getBalanceFactor(root);
        if(std::abs(balanceFactor)>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
```