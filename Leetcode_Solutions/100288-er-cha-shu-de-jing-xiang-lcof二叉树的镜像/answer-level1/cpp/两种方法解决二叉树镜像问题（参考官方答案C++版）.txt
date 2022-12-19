
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
         //第一种：利用python a,b =b,a的平行写法
        // if(root ==NULL) return NULL;
        // TreeNode* tmp =root->left;
        // root->left =  mirrorTree(root->right);
        // root->right =  mirrorTree(tmp);
        // return root;
        //第二种方法：利用辅助栈
        stack<TreeNode*> s ;
        s.push(root);
        while(!s.empty()){
            TreeNode* node =s.top();
            s.pop();
            if(node !=NULL){
            if(node->left !=NULL) s.push(node->left);
            if(node->right!=NULL) s.push(node->right);
            TreeNode* tmp =node->left;
            node->left = node->right;
            node->right =tmp;
            }else{
                return NULL;
            }
        }   
        return root;
    }
};