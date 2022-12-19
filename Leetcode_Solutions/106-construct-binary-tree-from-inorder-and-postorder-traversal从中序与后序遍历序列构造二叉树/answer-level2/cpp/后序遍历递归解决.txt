后序遍历的结果从后向前看,都是当前区间的根节点,然后在中序遍历中寻找根节点,将其分割成两个区间,分别为根节点的右左子树.
```
class Solution {
    TreeNode *postordered(vector<int> &inorder, vector<int> &postorder, int begin, int end, int &pos){
        if(pos<0 || begin>=end) return NULL;
        TreeNode *r= new TreeNode(postorder[--pos]);
        int cur=0;
        for(cur=begin; cur<end && inorder[cur]!=r->val; ++cur);
        r->right=postordered(inorder,postorder,cur+1,end,pos);
        r->left=postordered(inorder,postorder,begin,cur,pos);
        return r;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos=postorder.size();
        return postordered(inorder,postorder,0,inorder.size(),pos);
    }
};
```
