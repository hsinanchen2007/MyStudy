
一、首先想到和判断平衡二叉树一样的思路
二、考虑返回的值，分为三种情况，1、当前节点值2、当前节点值+左子树值之和3、当前节点值+右子树值之和
三、考虑最大路径和，分为两大类1、返回的值和父节点可以构成更大的路径和2、当前节点所包含的最大路径和大于最大值。
class Solution {
public:
    int max1=INT_MIN;
    void count(TreeNode* now, int&sum)
    {
        int l,r;
        if(now==NULL)
        {
            sum=0;
        }
        else if(now->left==NULL&&now->right==NULL)
        {
            sum=now->val;
            max1=max(max1,sum);
        }
        else
        {
            count(now->left,l);
            count(now->right,r);
            sum=max(max(now->val+r,now->val),now->val+l);
            max1=max(max1,max(sum,now->val+r+l));
        }
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        count(root,sum);
        return max1;
    }
};