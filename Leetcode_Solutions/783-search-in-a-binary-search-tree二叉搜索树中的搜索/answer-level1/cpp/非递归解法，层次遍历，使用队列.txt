```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(!root)
            return root;
        
        std::queue<TreeNode*> vecTr;
        vecTr.push(root);
        
        while(!vecTr.empty())
        {
            TreeNode* node = vecTr.front();
            vecTr.pop();
            if(node->val == val)
                return node;
            
            if(node->left)
                vecTr.push(node->left);
            
            if(node->right)
                vecTr.push(node->right);
        }
        
        return NULL;
    }
};
```



