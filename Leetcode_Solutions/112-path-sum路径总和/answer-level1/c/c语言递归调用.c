### 解题思路
递归调用，判断一个二叉树有没有目标sum的路径，就是看这个二叉树的根节点下面的两棵子数有没有目标为（sum-当前根节点的值）的路径
递归终止条件
     1.根节点为空，return false，如果走到这一步，一定不是叶子节点，那么这条路径不是一条有效路径，因为如果是叶子节点，会在下一条条件出终止
     2.根节点没有子树，说明是叶子节点，如果此时val == sum 那么就return true，否则return false
注意：终止条件1， 2顺序不能交换，如果交换，而对于题目给出的空树就会报错（非法访问root->left， root-right）
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//递归调用，判断一个二叉树有没有目标sum的路径，就是看这个二叉树的根节点下面的两棵子数有没有目标为（sum-当前根节点的值）的路径
//递归终止条件
//    1.根节点为空，return false，如果走到这一步，一定不是叶子节点，那么这条路径不是一条有效路径，因为如果是叶子节点，会在下一条条件出终止
//   2.根节点没有子树，说明是叶子节点，如果此时val == sum 那么就return true，否则return false
//注意：终止条件1， 2顺序不能交换，如果交换，而对于题目给出的空树就会报错（非法访问root->left， root-right）


bool hasPathSum(struct TreeNode* root, int sum)
{
    if(!root)   return false;
    if(!root->left && !root->right)
    {
         if(root->val == sum)
            return true; 
            return false;
    }     
     return hasPathSum(root->left, sum - root->val) ||  hasPathSum(root->right, sum - root->val);
}
```