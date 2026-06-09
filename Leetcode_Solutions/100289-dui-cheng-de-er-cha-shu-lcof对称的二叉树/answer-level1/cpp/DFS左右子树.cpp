
镜像对称要求的条件可以层层递进
1. 左右子树必须同时存在或者不存在
2. 左右子树的子节点必须对称相同

因此，递归的退出条件就是
1. 左右子树都无了，说明一整条路径都正确, return true
2. 左右子树有一个无了，说明错误，return false
3. 左子树右节点不等于右子树左节点，或者左子树左节点不等于右子树右节点，return false


因此每一次递归的是**左子树的右节点和右子树的左节点**与**左子树的左节点和右子树的右节点**
```
    class Solution {
    public:
        bool dfs(TreeNode *l, TreeNode *r){ 
            if(!l&&!r) return true;
            if(!l||!r) return false;
            if(l->val!=r->val) return false; 
            return dfs(l->left, r->right) && dfs(l->right, r->left);
        }
        bool isSymmetric(TreeNode* root) {
            if(!root||(!root->left&&!root->right)) return true;
            
            return dfs(root->left, root->right);
            
        }
    };
```