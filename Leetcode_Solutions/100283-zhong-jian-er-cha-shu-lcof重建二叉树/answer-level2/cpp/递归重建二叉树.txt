**解题思路**
利用前序遍历找到根节点，然后利用中序遍历找到左右子树的位置，依次递归。
```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int lenth=preorder.size();
        if(lenth<=0) return NULL;
        int startPre=0,endPre=lenth-1,startIn=0,endIn=lenth-1;
        return constructTree(startPre,endPre,startIn,endIn,preorder, inorder);
    }

    TreeNode* constructTree(int startPre,int endPre,int startIn,int endIn,vector<int>& preorder, vector<int>& inorder)
    {
        if(startPre>endPre)
        return NULL;
        TreeNode* root=new TreeNode(preorder[startPre]);
        int leftTree=0;
        while(inorder[startIn+leftTree]!=preorder[startPre])
        {
            leftTree++;
        }
        root->left=constructTree(startPre+1,startPre+leftTree,startIn,startIn+leftTree-1,preorder, inorder);
        root->right=constructTree(startPre+leftTree+1,endPre,startIn+leftTree+1,endIn,preorder, inorder);
        return root;
    }
};
```
