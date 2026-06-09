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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
         if(postorder.size()==0||inorder.size()==0)return 0;
        auto root=new TreeNode(postorder.back());
        int index;
        for(int i=0;i!=inorder.size();++i)
        {
            if(inorder[i]==root->val)
            {
                index=i;
            }
        }
        
        vector<int>l_in(inorder.begin(),inorder.begin()+index);
        vector<int>r_in(inorder.begin()+index+1,inorder.end());
        vector<int>l_po(postorder.begin(),postorder.begin()+l_in.size());
        vector<int>r_po(postorder.begin()+l_in.size(),postorder.end()-1);
        root->left=buildTree(l_in,l_po);
        root->right= buildTree(r_in,r_po);
        return root;

        
    }
};
```

1. 由中序遍历确定根节点
2. 根据第一步得到的根节点，分别确定左右子树的中序遍历和后序遍历
3. 递归
