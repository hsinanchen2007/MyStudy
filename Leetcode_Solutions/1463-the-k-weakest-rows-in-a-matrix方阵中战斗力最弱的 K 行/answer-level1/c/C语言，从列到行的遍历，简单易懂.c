```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int i, j, count = 0;
    int *res = (int *)malloc(sizeof(int) * (matSize + 1));
    memset(res, 0, sizeof(int) * (matSize + 1));
    for(i = 0;i < (*matColSize);i++)
    {
        for(j = 0;j < matSize;j++)//从列入手，从上到下，先遇到0就说明战斗力是目前最弱的
        {
            if(mat[j][i] == 0)
            {
                if(count == k)//先判断count是否等于k，等于说明已满
                {
                    break;
                }
                int flag = 1;
                for(int k = 0;k < count;k++)//判断该行是否已被存
                {
                    if(res[k] == j)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                    res[count++] = j;
                
            }
        }
    }
    if(count < k)//有0的行数小于k，数组下标还没有存到k
    {
        for(i = 0;i < matSize;i++)
        {
            int flag = 1;
            for(j = 0;j < count;j++)//判断该行是否已被存
            {
                if(i == res[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                res[count++] = i;
        }
    }
    *returnSize = k;
    return res;
}
```
