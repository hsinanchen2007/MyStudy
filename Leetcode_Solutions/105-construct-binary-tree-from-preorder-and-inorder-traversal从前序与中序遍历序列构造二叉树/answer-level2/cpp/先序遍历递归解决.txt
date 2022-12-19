先序遍历结果,每一个值都是当前区间的根r,由当前根r在中序遍历中寻找r,将其分割成两个区间left,right,分别对应当前根的左右子树.
```
class Solution {
    TreeNode *preordered(vector<int> &preorder, vector<int> &inorder, int begin, int end, int &pos){
        if(begin>=end || pos>=preorder.size()) return NULL;
        TreeNode *r=new TreeNode(preorder[pos++]);
        int cur=0;
        for(cur=begin; cur<end && inorder[cur]!=r->val; ++cur);
        r->left=preordered(preorder,inorder,begin,cur,pos);
        r->right=preordered(preorder,inorder,cur+1,end,pos);
        return r;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos=0;
        return preordered(preorder,inorder,0,inorder.size(),pos);
    }
};
```
