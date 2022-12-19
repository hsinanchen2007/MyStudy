```
class Solution {
public:
    
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        //if(root == NULL) return -1;
        queue<TreeNode*> qu;
        qu.push(root);
        
        while(!qu.empty()){
            root = qu.front();
            qu.pop();
            if(root->right != NULL){
                qu.push(root->right);
            }
            if(root->left != NULL){
                qu.push(root->left);
            }
        }
        return root->val;
    }
};
```
广度优先遍历，只不过先存入右节点，然后再存入左节点，遍历结束，最后一个节点刚好是答案
