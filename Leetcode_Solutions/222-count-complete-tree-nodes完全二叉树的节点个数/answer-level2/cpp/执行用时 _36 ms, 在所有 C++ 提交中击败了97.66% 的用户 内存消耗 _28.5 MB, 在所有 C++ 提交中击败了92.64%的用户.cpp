class Solution {
public:
    int countNodes(TreeNode* root) {
        
        int count = 0;
        if(root== nullptr)
            return 0;
        count =1;
        if(root->left != NULL){
            count += countNodes(root->left);
        }
        if(root->right != NULL){
            count +=countNodes(root->right);
        }
        return count;
    }
};