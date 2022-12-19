定义计数count,递归访问二叉树结点，如果二叉树节点不为null则计数++。
int x=[]{
     std::ios::sync_with_stdio(false);
     cin.tie(0);
     return 0;
 }();

class Solution {
public:
    int count = 0;
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        countNodes(root->left);
        countNodes(root->right);
        if(root){
             count++;
        }
        return count;     
    }
};