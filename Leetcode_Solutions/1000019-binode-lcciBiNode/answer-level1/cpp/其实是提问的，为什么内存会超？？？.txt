如果把root->left = NULL;
换成pre->left = NULL;
实际证明答案是不变的，但是内存会超，我没想明白？有哪位大神解释一下。

class Solution {
public:
TreeNode* pre;
    TreeNode* convertBiNode(TreeNode* root)
    {
        TreeNode* temp_first;
        temp_first = new TreeNode(0);
        pre = temp_first;
        convertBiNode_(root);
        return temp_first->right;
    }
    void convertBiNode_(TreeNode* root) {
        if(root == NULL)
            return;
        if(root->left != NULL)
            convertBiNode_(root->left);
        root->left = NULL;
        //pre->left = NULL;
        pre->right = root;
        pre = root;
        if(root->right != NULL)
            convertBiNode_(root->right);
        
    }
};

