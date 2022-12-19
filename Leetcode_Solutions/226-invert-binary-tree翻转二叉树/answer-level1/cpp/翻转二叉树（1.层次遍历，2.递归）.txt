**递归**
```
typedef struct TreeNode* ptr;
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root || (!root->left && !root->right))
        return root;
    ptr r = invertTree(root->right);
    ptr l = invertTree(root->left);
    root->left = r;
    root->right = l;
    return root;
}
```
**层次遍历，遍历到每一个节点时交换其左右孩子即可。**
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *p, *t;
        while(!q.empty()){
            p = q.front();
            q.pop();

            swap(p->left, p->right);

            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
        }
        return root;
    }
};
```