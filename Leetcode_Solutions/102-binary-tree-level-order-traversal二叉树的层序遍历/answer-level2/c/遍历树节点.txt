### 解题思路
遍历树节点，存到数组里面，然后转换成对外输出的数组，应该还可以优化合并

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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct TreeNode** tmpArr;
    int** retArr = NULL;
    int beg = 0;
    int end = 1;
    int curRowNum = 1;
    int nextRowNum = 0;
    int treeRow[1000] = {0};
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    tmpArr = (struct TreeNode*)malloc(sizeof(struct TreeNode*)*10000);
    memset(tmpArr,0,sizeof(struct TreeNode*)*10000);
    retArr = (int **)malloc(sizeof(int*)*1000);

    for(int i = 0; i <1000; i++){
        retArr[i] = (int*)malloc(sizeof(int)*2000);
        memset(*retArr,0,sizeof(int)*2000);
    }
    tmpArr[0] = root;
    while(tmpArr[beg] != NULL){
        if(tmpArr[beg]->left != NULL){
            tmpArr[end] = tmpArr[beg]->left;
            //printf("left val %d, index %d \r\n",tmpArr[end]->val,end);
            end++;
        }
        if(tmpArr[beg]->right != NULL){
            tmpArr[end] = tmpArr[beg]->right;
            //printf("right val %d, index %d \r\n",tmpArr[end]->val,end);
            end++;
        }
        //printf("val %d, beg %d \r\n",tmpArr[beg]->val,beg);
        beg++;      
    }

    beg = 0;end = 0;
    for(int i = 0; i < 1000; i++){
        treeRow[i] = curRowNum;
        end++;
        for(int j = 0; j < curRowNum; j++){
            //printf("nex %d,cur %d, beg %d,val %d\r\n",nextRowNum,curRowNum,beg,tmpArr[beg]->val);
            retArr[i][j] = tmpArr[beg]->val;           
            if(tmpArr[beg]->left != NULL){
                nextRowNum++;
            }
            if(tmpArr[beg]->right != NULL){
                nextRowNum++;
            }
            //printf("retarr %d, i %d, j %d,nex %d,cur %d, beg %d,val %d\r\n",retArr[i][j],i,j,nextRowNum,curRowNum,beg,tmpArr[beg]->val);
            beg++;
        }
        if(nextRowNum == 0){
            break;
            //end = i;//总共有多少行
        }else{
            curRowNum = nextRowNum;
            nextRowNum = 0;
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int)*end);
    for(int k = 0; k < end; k++){
        if(treeRow[k] == 0){
            break;
        }
        (*returnColumnSizes)[k] = treeRow[k];
       // printf("rowbum %d end %d\r\n",(*returnColumnSizes)[k],end);
    }
    *returnSize = end;
    free(tmpArr);
    return retArr;
}
```