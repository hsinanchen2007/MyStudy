**效率还是不错的，击败了90%以上的用户。参考如下:**


```
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct TreeNode **treeArray = malloc(10000 * sizeof(struct TreeNode *));
    *returnSize = 0;
    *returnColumnSizes = malloc(10000* sizeof(int));
    int **NumArry = malloc(10000* sizeof(int *));
    bool LeftToRight = true;
    int LastLinePos = 0;
    int nowlinePow = 0;
    int LoopNum = 0;
    int i = 0;
    int targetPos = 0;

    if (root == NULL)
    {
        return NULL;
    }

    treeArray[nowlinePow++] = root;
    LeftToRight = false;
    //printf("function reach here! \n");
    while (LastLinePos < nowlinePow){
        LoopNum = nowlinePow - LastLinePos;
        //printf("nowlinePow = %d, LastLinePos = %d \n", nowlinePow, LastLinePos);
       
        NumArry[*returnSize] = malloc(sizeof(int) * LoopNum);
        (*returnColumnSizes)[*returnSize] = LoopNum;  //记录这行数组的长度
        //printf("loopNum = %d, returnSize = %d \n", LoopNum, *returnSize);

        for (i = 0; i < LoopNum; i++){
            targetPos = LastLinePos + LoopNum - i - 1;
            if (LeftToRight == false){
                if (treeArray[targetPos]->right != NULL){
                    treeArray[nowlinePow++] = treeArray[targetPos]->right;
                }
                if (treeArray[targetPos]->left != NULL){
                    treeArray[nowlinePow++] = treeArray[targetPos]->left;
                }
            }else{
                if (treeArray[targetPos]->left != NULL){
                    treeArray[nowlinePow++] = treeArray[targetPos]->left;
                }
                if (treeArray[targetPos]->right != NULL){
                    treeArray[nowlinePow++] = treeArray[targetPos]->right;
                }
            }
            //printf("i = %d, targetPos = %d \n", i, targetPos);
            NumArry[*returnSize][i] = treeArray[LastLinePos + i]->val;
            //printf("treeArray[targetPos]->val = %d \n", treeArray[targetPos]->val);
        }
        LastLinePos += LoopNum;
        (*returnSize)++;  //下一行数组
        
        //printf("LeftToRight = %x \n", LeftToRight);
        LeftToRight = !LeftToRight;  //换方向
    }
    return NumArry;
}
```
