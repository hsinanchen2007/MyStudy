因为二叉搜索树满足左值<中指<右值，有了这个性质之后在求解时可以通过对比根节点的值和左右节点值的大小确定出公共祖先出现的位置，继续求解即可。
递归解法如下：
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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val>max(p->val,q->val)) return lowestCommonAncestor(root->left,p,q);
        else if(root->val<min(p->val,q->val)) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};
```

迭代写法如下：
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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        while(true){
            if(root->val>max(p->val,q->val)) root=root->left;
            else if(root->val<min(p->val,q->val)) root=root->right;
            else break;
        }
        return root;
    }
};
```