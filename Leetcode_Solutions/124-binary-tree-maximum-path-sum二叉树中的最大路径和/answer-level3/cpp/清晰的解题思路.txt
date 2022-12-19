**思路写在代码里了，感觉还是比较清晰的**
感觉有点面向if-else编程  哈哈哈哈哈
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
    int maxPathSum(TreeNode* root) {
        int max = -10000;
        solve(root,&max);
        return max;
    }
    int solve(TreeNode *root,int *max)
    {
        //得到左子树最大值
        //得到右子树最大值
        //将左子树的值与当前节点值相加（记为l），右子树与当前节点值相加(记为r)，三者相加
        //挑出最大的与max比较，同时更新max（感觉有点动态规划的味道，虽然我还没学hhh，赶紧去补一补）
        //返回l与r的最大值，若两者都小于0,则返回0
        //补充一下为什么返回0
        //记返回的值为curSum
        //因为我们自底向上遍历，若l与r同时小于0，则子树的值不可能使路径增大（因为curSum+父节点的值<父节点 
        //的值，所以我们只需从当前节点的父节点开始遍历
        //注意，我们需要假设开始的最大值（即max）是一个很小的数，不然无法通过全是负数的测试
        if(!root)
            return 0;
        int l = solve(root->left,max);
        int r = solve(root->right,max);
        int leftSum = l+root->val;
        int rightSum = r+root->val;
        if(rightSum+leftSum-root->val>*max)
            *max = leftSum+rightSum-root->val;
        if(leftSum>*max)
            *max =leftSum;
        if(rightSum>*max)
            *max = rightSum;
        if(leftSum>0||rightSum>0)
        {
            return (leftSum>rightSum)?leftSum:rightSum;
        }
        else
            return 0;
    }
};
```