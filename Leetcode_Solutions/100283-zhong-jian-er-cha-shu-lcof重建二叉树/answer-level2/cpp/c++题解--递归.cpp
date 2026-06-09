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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty())
            return nullptr;
        return building(&preorder[0],&inorder[0],&preorder[0]+preorder.size()-1,&inorder[0]+inorder.size()-1);
    }
    TreeNode* building(int* startPreorder,int* startInorder,
                       int* endPreorder,int* endInorder)
    {
        TreeNode* pNode=new TreeNode(*startPreorder);//动态
        pNode->left=pNode->right=nullptr;
        if(startPreorder==endPreorder)
            return pNode;
        int* rootInorder=startInorder;
        while(rootInorder<=endInorder&&*rootInorder!=pNode->val)
            rootInorder++;
        if((rootInorder-startInorder)>0)
            pNode->left=building(startPreorder+1,startInorder,startPreorder+(rootInorder-startInorder),rootInorder-1);
        if((endInorder-rootInorder)>0)
            pNode->right=building(startPreorder+(rootInorder-startInorder)+1,rootInorder+1,endPreorder,endInorder);
        return pNode;
    }
};
```
