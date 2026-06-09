int *g_rowtmp;
int *g_col;
int **g_res;
int g_rowindex = 0;
int g_colindex = 0;

int cmp(const void *a, const void *b)
{
    int keya = *(int *)a;
    int keyb = *(int *)b;

    return keya-keyb;
}

void OutPutoneres(int max, int numsSize)
{       
    g_col[g_rowindex] = max;    
    for (int i = 0; i < max; i++)
    {             
        g_res[g_rowindex][i] = g_rowtmp[i];   
    }
   
    g_rowindex++;   

    return;
}

void PlaceQue(int i, int* nums)
{
    g_rowtmp[g_colindex] = nums[i];      
    g_colindex++;

    return;
}

void Buildres(int max, int index, int* nums, int numsSize)
{
    if (g_colindex >= max)
    {
        OutPutoneres(max, numsSize);
        return;
    }    
  
    for (int i = index; i < numsSize; i++)
    {        
        if (i > index && nums[i] == nums[i - 1])
        {
            continue;
        }
        PlaceQue(i, nums);
        Buildres(max, i + 1, nums, numsSize);              
        g_colindex--;                          
    }

    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
     int totoalrow = pow(2, numsSize);
    g_colindex = 0;
    g_rowindex = 0;

    g_rowtmp = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        g_rowtmp[i] = 0;
    }

    g_col = (int *)malloc(sizeof(int) * totoalrow);    
    g_res = (int **)malloc(sizeof(int *) * totoalrow);
    for (int i = 0; i < totoalrow; i++)
    {        
        g_res[i] = (int *)malloc(sizeof(int) * numsSize);        
    }    

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i <= numsSize; i++)
    {           
        Buildres(i, 0, nums, numsSize);                  
    }

    *returnSize = g_rowindex;
    *returnColumnSizes = g_col;
    return g_res;

}