### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int g_cnt =0;
int *g_len = NULL;
int maxsize = 1000;

int compare(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

 void fundigui(int target,int *candidates,int candidatesSize,int *tmpshu,int **result,int index,int beginpos)
 {
    int i=0;
    int tmp=0;
    
    for(i=beginpos;i<candidatesSize;i++)
    {
        if(target > candidates[i])
        {
            tmp = target-candidates[i];
            tmpshu[index] = candidates[i];
            fundigui(tmp,candidates,candidatesSize,tmpshu,result,index+1,i);
        }
        else if(target == candidates[i])
        {
            tmpshu[index++] = candidates[i];
            result[g_cnt] = (int*)malloc(sizeof(int)*index);
            g_len[g_cnt] = index;
            
            memcpy(result[g_cnt],tmpshu,sizeof(int)*index);
            /*printf("zxy %u %u\n",g_cnt,index);
            for(j=0;j<index;j++)
            {
                //printf("zxy zxy %u\n",tmpshu[j]);
                printf("zxy zxy %u\n",result[g_cnt][j]);
            }*/
            g_cnt++;
            
            return ;
        }
        
    }
 }

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    int i=0;
    
    int **result = (int**)malloc(sizeof(int*)*maxsize);
    int *tmpshu = (int*)malloc(sizeof(int)*maxsize);
    
    g_len = (int*)malloc(sizeof(int)*maxsize);
   
    memset(tmpshu,0,sizeof(int)*maxsize);
    memset(g_len,0,sizeof(int)*maxsize);
    qsort(candidates, candidatesSize, sizeof(int), compare);

    fundigui(target,candidates,candidatesSize,tmpshu,result,0,0);
    returnColumnSizes[0] = (int*)malloc(sizeof(int)*g_cnt);

    for(i=0;i<g_cnt;i++)
    {
        returnColumnSizes[0][i] = g_len[i];
        
    }
    *returnSize = g_cnt;
    
    g_cnt =0;
    free(g_len);
    free(tmpshu);
    tmpshu = NULL;
    g_len = NULL;

    return result;
}

```