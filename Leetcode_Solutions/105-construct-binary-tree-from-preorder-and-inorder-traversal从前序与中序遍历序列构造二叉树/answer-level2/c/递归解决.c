### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
   
    if(preorder==NULL||inorder==NULL||preorderSize<=0||inorderSize<=0){
         return NULL;
    }


        int rootValue = preorder[0];
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode*)*3);
        root->val = rootValue;
        root->left = NULL;
        root->right = NULL;

        //递归边界
        if(preorder==preorder+preorderSize-1){
            if(inorder==inorder+inorderSize-1 && *preorder==*inorder){
                return root;
            }
        }

        //在中序遍历中查找根结点
        int* rootIn = inorder;
        while(rootIn<=(inorder+inorderSize-1) && *rootIn!=rootValue){
            rootIn++;
        }

        int leftLength = rootIn - inorder;//左子树长度
        int rightLength = inorder + inorderSize -1 - rootIn;//右子树长度

        if(leftLength>0){ root->left = buildTree(preorder+1,leftLength,inorder,leftLength) ;}//构建左子树
        if(rightLength>0){root->right = buildTree(preorder+leftLength+1,rightLength,rootIn+1,rightLength);//构建右子树}
        return root;

}