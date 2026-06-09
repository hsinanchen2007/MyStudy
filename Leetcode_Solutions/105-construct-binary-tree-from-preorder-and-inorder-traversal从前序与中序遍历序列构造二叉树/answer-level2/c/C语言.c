### 解题思路
此处撰写解题思路
递归就完事儿了哥哥们。
Preorder: ROOT [LEFT SUBTREE PREORDER] [RIGHT SUBTREE PREORDER]
inorder   : [LEFT SUBTREE    INORDER] ROOT [RIGHT SUBTREE INORDER]
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
        if(preorderSize == 0)
        return NULL;

        struct TreeNode* root = malloc(sizeof(struct TreeNode));
        int leftsize = 0; 
        int rightsize; // update pre/in oreder size
        root->val = preorder[0];
        for(int i=0;i<inorderSize;i++){
            if(inorder[i] == preorder[0])
                break;
            else
                leftsize ++ ;
        }//calculate the left tree size


        rightsize = preorderSize - 1 - leftsize;
    //get the right sub tree size
        root->left = buildTree(preorder+1,leftsize,inorder,leftsize);
        root->right = buildTree(preorder+1+leftsize,rightsize,inorder+1+leftsize,rightsize);
     //recursive!

        return root;

}
```