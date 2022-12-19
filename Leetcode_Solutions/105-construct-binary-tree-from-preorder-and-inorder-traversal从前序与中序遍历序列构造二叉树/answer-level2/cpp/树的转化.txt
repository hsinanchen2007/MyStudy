![image.png](https://pic.leetcode-cn.com/d92a711bfb7373615dbab8024c1b42fffcabd5d7315d2d02728cedae2d717173-image.png)

```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return binarytree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);//输入preorder的left right与inorder的left right
    }
     
    TreeNode* binarytree(vector<int>& preorder, vector<int>& inorder,int lp,int rp,int li,int ri){
        if(lp>rp || li>ri) return NULL;
        TreeNode *root = new TreeNode(preorder[lp]);
        int i = li;
        for(;inorder[i] != root->val;i++);
        int llen = i-li;
        root->left =binarytree(preorder,inorder,lp+1,llen+lp,li,i-1);
        root->right=binarytree(preorder,inorder,llen+lp+1,rp,i+1,ri);
        return root;
    }
};



```
