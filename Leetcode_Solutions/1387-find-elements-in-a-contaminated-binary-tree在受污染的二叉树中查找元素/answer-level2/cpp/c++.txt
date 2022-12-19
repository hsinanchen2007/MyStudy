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
class FindElements {
    TreeNode* r;
public:
    FindElements(TreeNode* root) {
        r=root;
        lalala(root,0);
    }
    void lalala(TreeNode* root,int val){
        if(root==NULL)return;
        root->val=val;
        lalala(root->left,2*val+1);
        lalala(root->right,2*val+2);
    }
    
    bool find(int target) {
        TreeNode* root=r;
        return lala(target,root);
    }

    bool lala(int target,TreeNode* root){
        if(root==NULL)return false;
        if(root->val>target)return false;
        if(root->val==target)return true;
        return lala(target,root->left)|lala(target,root->right);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
```
