```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //二叉搜索树 中序遍历的结果是有序的
 // 进行中序遍历 然后将前一个结果存下来 与当前结果对比 如果两个相减的绝对值小于min 则更改min
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        TreeNode *p=root->left?root->left:root->right;
        int min=abs(root->val-p->val);//记录最小的差
        int pre=0;//记录中序遍历的前一个的值
        int flag=0;//为0时 还未遍历到第一个中序节点 为1时 pre已经有值
        post_order(root,pre,min,flag);
        return min;
        
    }
    void post_order(TreeNode* root,int &pre,int &min,int& flag)
    {
        if(!root) return;
        post_order(root->left,pre,min,flag);
        if(flag==0){pre=root->val;flag=1;}
        else
        {
            min=abs(pre-root->val)<min?abs(pre-root->val):min;
            pre=root->val;
        }
        post_order(root->right,pre,min,flag);
    }
};
```
