### 解题思路
![image.png](https://pic.leetcode-cn.com/2998ddf1523c49b4762fb348959ff4b8e8bfc5d0527fa226cf1aed53c467d8ce-image.png)


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


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(NULL == inorder || inorder <=0 || NULL == postorder || postorderSize <= 0)
    {
        return NULL;
    }

    struct TreeNode *res = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    res->val = postorder[postorderSize -1]; 
    int idx = -1;
    for(int i = 0;i < inorderSize;i++)
    {
        if(inorder[i] == res->val)
        {
            idx = i;
            break;
        }
    }

    res->left  = buildTree(inorder,idx,postorder,idx);
    res->right = buildTree(inorder+idx+1,inorderSize-1-idx,postorder+idx,postorderSize-1-idx);
    
    return res;
    
}
```