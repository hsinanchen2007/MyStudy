#### 解题思路

<![image.png](https://pic.leetcode-cn.com/a1e8b314f108dea2674a960ba763760497c049aebe1e4177f42f58f591b93684-image.png),![image.png](https://pic.leetcode-cn.com/29168fc45e3208fa5084d4212e79151f536b7195810696cd7c180a6f4658e8a2-image.png),![image.png](https://pic.leetcode-cn.com/51b984920b87e3a991ed72eea53380227ca5a7826fff146453f0bc4e662c2ed0-image.png),![image.png](https://pic.leetcode-cn.com/4c4abe5815aa278db507a69bdad000f02aaa4000975cb72324372aa58b7006f7-image.png),![image.png](https://pic.leetcode-cn.com/658f75e0916fa5abe63c84f6e2a9a02a29fce15d6421cbd5ae3f87d552974048-image.png)>

#### 代码

```C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* construct(int* preorder, int preleft,int preright, int* inorder, int inleft,int inright){
    int i,leftson;
    if(preleft>preright)return NULL;
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=preorder[preleft];
    for(i=inleft;i<=inright;i++){
        if(inorder[i]==root->val)break;
    }
    leftson=i-inleft;
    root->left=construct(preorder,preleft+1,preleft+leftson,inorder,inleft,i-1);
    root->right=construct(preorder,preleft+leftson+1,preright,inorder,i+1,inright);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return construct(preorder, 0, preorderSize - 1, inorder, 0 ,inorderSize - 1);
}
```