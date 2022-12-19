遍历节点，判断当前节点的左右子树是需要金币还是有多余的金币，find函数的返回值是需要金币的数量，如果有多余的金币返回值为负值。如果左子树需要金币a枚，那么这a枚金币一定会经过根节点和根节点的左节点到左子树，如果左子树有多余的b枚金币，那么这b枚金币一定会经过根节点的左节点和根节点到右子树。而具体如何实现，只需要让当前节点的左右节点值加上需要的金币数然后递归处理就可以了。
```
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        if(!root)
            return 0;
        int l=need(root->left);
        int r=need(root->right);
        if(root->left)
            root->left->val+=l;
        if(root->right)
            root->right->val+=r;
        return abs(l)+distributeCoins(root->left)+abs(r)+distributeCoins(root->right);
    }
    
    int need(TreeNode *root){
        if(!root)
            return 0;
        return need(root->left)+need(root->right)+1-root->val;
    }
};
```
