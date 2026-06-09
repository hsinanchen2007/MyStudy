```
class Solution {
private:
    int p(TreeNode *node){
        if(!node)   return 0;
        else if(node->left && node->right)
            return min(p(node->left), p(node->right))+1;
        else
            return max(p(node->left), p(node->right))+1;
    }
public:
    int minDepth(TreeNode* root) {
        return p(root);
    }
};
```
