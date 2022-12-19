时间复杂度：O(n)  空间复杂度：O(n)

```
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root)
    {
        int **matrix=(int **)malloc(sizeof(int *)*1);
        *returnSize = 0;
        return matrix;
    }

    int **matrix = (int **)malloc(sizeof(int*)*1000);
    returnSize[0] = (int)malloc(sizeof(int)*1); // returnSize[0] 存储matrix的长度
    struct TreeNode *queue[1100]; // 如果设为1000，无法通过最大测试用例
    int l = 0,r=0,level =0,retSize = 0;
    queue[r++]=root;
    while(l<r)
    {
        retSize++;
        (*returnColumnSizes)[level] = r-l; // 当前深度的节点总数
        matrix[level] =(int*)malloc(sizeof(int)*(r-l));

        int t = r,i;
        for(i=0;l<t;l++,i++)
        {
            struct TreeNode *p = queue[l];
            matrix[level][i]=p->val;
            if(p->left) queue[r++]=p->left;
            if(p->right) queue[r++]=p->right;
        }
        level++;
    }
    returnSize[0]=retSize;
    return matrix;

}
```

