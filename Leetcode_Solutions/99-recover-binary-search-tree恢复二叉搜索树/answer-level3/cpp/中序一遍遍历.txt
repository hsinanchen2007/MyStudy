```
class Solution {
public:
    TreeNode* last = NULL, *node1, *node2;
    bool flag=false;
    void DFS(TreeNode* root){
        if(!root) return;
        DFS(root->left);
        if(last && root->val<=last->val){
            if(!flag) node1=last, node2=root, flag=true;
            else node2 = root;
        }
        last = root;
        DFS(root->right);
    }

    void recoverTree(TreeNode* root) {
        DFS(root);
        int t=node1->val;
        node1->val = node2->val;
        node2->val = t;
    }
};
```
