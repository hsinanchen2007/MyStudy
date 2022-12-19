观察题目后发现，可以递归更新各个节点的左右孩子的键值，然后判断该节点**是否为叶子节点**并且**路径和是否等于sum**。
（1）:分析返回false的情况，因为要递归左右字树，最后函数调用的节点为空，于是可以用if(!root){ return false; }
（2）:分析返回true的情况，根据上面所述返回true的条件为if(!root->left && !root->right && root->val == sum);
这两个条件语句放在前面，当不满足这两种情况时。判断当前节点孩子情况：若孩子不为空，孩子的键值加上父亲的键值即可。
最后递归调用：return (hasPathSum(root->left,sum) || hasPathSum(root->right,sum));
 ```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    if(!root)
        return false;
    if (!root->left && !root->right && root->val == sum)
        return true;
    if(root->left)
        root->left->val += root->val;
    if(root->right)
        root->right->val += root->val;
    return (hasPathSum(root->left,sum) || hasPathSum(root->right,sum));
        
}
```
