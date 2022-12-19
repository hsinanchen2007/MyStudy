// 如果都小于当前节点，那么在它的左子树上，都大于当前节点，那么在它的右子树上
 // 如果一个大于一个小于，那么返回当前节点，如果当前节点的值等于某一个值，那么返回当前节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val1 = p->val;
        int val2 = q->val;
        if(val1>val2){
            int t = val1;
            val1 = val2;
            val2 = t;
        }// 保证val1小于val2
        while(true){
            if(root->val==val1 || root->val==val2)
                return root;
            if(root->val>val1 && root->val<val2)
                return root;
            if(val1<root->val && val2<root->val)
                root=root->left;
            else
                root=root->right;
        }
    }
};