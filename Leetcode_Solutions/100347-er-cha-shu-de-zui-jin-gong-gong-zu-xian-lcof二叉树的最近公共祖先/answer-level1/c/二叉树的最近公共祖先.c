```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
对于一个公共祖先（一定有子节点才能当祖先）来说，其两个子节点 p、q 有三种分布情况
1 p, q 分别位于 x 的左子树和右子树；
2 p, q 都在 x 的左子树（也包括祖先其自身，另一个字节点在左子树）；
3 p, q 都在 x 的右子树（也包括祖先其自身，另一个字节点在右子树）；

上述3条规律对每一子树都成立， 所以只要检查每个节点的 左右子树即可， 所以要用后续遍历

*/
int flagP = 0;
int flagQ = 0;
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root){
        return NULL;
    }
    if (root == p || root == q){
        return root;
    }
    struct TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    if (left && right){ //  p, q 分别位于 x 的左子树和右子树；
        return root;
    }else if (left){ // p, q 都在 x 的左子树（也包括祖先其自身，另一个字节点在左子树）；
        return left;
    }else if (right){ // p, q 都在 x 的右子树（也包括祖先其自身，另一个字节点在右子树）；
        return right;
    }
    return NULL;
}
```
