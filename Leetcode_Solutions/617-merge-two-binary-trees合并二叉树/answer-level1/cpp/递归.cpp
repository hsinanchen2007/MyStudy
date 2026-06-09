class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1&&t2)
        {t1->val+=t2->val;
             t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
         
        }
        return (t1==NULL)?t2:t1;
       
    }
};//算法中递归用的很多
//这个算法的问题是合并后的树节点位置要改变吗？，是要改变，那如何进行改变？？？？
//digui???//这里的树不是avl树，并不需要改变节点的位置