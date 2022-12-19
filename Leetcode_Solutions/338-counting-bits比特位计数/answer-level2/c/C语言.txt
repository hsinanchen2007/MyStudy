### 解题思路
动态规划，C代码

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    *returnSize = num + 1;
    int *arrayRet = (int *)malloc(sizeof(int) * (num + 1));
    int i;
    for(i = 0; i < num + 1; i++)
    {
        if(i == 0) arrayRet[i] = 0;
        else
            arrayRet[i] = arrayRet[i/2] + i%2;
    }
    return arrayRet;
}
```