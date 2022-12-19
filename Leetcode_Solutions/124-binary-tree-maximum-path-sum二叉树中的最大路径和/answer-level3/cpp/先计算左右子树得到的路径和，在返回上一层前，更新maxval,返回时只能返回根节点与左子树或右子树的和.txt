    class Solution {
    public:
        int maxPathSum(TreeNode* root) {
            if(root->left == NULL && root->right == NULL)
                return root->val;
            maxval = root->val;
            find(root);
            return maxval;
        }
    private:
        int maxval;
        int find(TreeNode* root)
        {
            if(root == NULL)
                return 0;
            
            int left = 0,right = 0;
            left  = find(root->left);
            right = find(root->right);
            int temp1,temp2,temp3;
            if(left != 0 || right != 0){//更新maxval时需分情况
                temp1 = max(maxval,max(left,right));//1.不考虑根节点
                temp2 = max(maxval,root->val+left+right);//2.三节点都考虑
                temp3 = max(maxval,root->val);//3.只考虑根节点
                maxval = max(temp3,max(temp1,temp2));
            }
            else//若左右子树返回的都是0，则表示左右子树均不需参加计算，只考虑根节点
                maxval = max(maxval,root->val);
            //返回上一层时，只能返回根节点与左子树或右子树的和，否则就不是一条正确的路径
            //若和小于0，直接返回0，表明该点不参与后续的计算
            if(root->val + max(left,right) <= 0)
                return 0;
            return root->val + max(left,right);
        }
    };