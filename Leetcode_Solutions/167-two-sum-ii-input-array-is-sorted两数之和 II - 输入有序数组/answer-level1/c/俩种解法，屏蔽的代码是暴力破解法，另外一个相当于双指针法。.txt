### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    /*int i,j;

    if(numbers ==  NULL || numbersSize <= 0)
        return NULL;

    *returnSize=0;
    for(i=0;i<numbersSize;i++)
    {
        for(j=i+1;j<numbersSize;j++)
        {
            if(numbers[i]+numbers[j] == target)
            {
                *returnSize=2;
                int *p = malloc(sizeof(int)*2);
                p[0]=i+1;
                p[1]=j+1;
                return p;
            }
        }
    }
    return NULL;*/
    if(numbers ==  NULL || numbersSize <= 0)
        return NULL;

    *returnSize=0;
    int start = 0;
    int end = numbersSize -1;

    while(start<end)
    {
        if(numbers[start]+numbers[end] == target)
        {
            int *p = (int *)malloc(sizeof(int)*2);
            p[0]=start+1;
            p[1]=end+1;
            *returnSize = 2;
            return p;
        }
        if(numbers[start]+numbers[end]>target)
            end--;
        else
            start++;
    }
    return NULL;
}
```