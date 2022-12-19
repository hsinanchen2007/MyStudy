### 解题思路
其实就是后序遍历求树高，在求每一颗树高的过程中在看看其左右子树之和是否为更大的直径长度。

### 代码

```c
int TreeHigh(struct TreeNode* root,int* result){
    if(!root){
        return 0;
    }
    int lh = TreeHigh(root->left,result);
    int rh = TreeHigh(root->right,result);
    if(lh+rh > *result){
        *result = lh+rh;
    }
    return (lh>rh?lh+1:rh+1);
}

int diameterOfBinaryTree(struct TreeNode* root){
    int result=0;
    TreeHigh(root,&result);
    return result;
}
```