### 解题思路


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int phigh,plow;
    phigh=numbersSize-1;
    plow=0;
    int *result=(int *)malloc(sizeof(int)*2);
    while(phigh>plow)
    {
        if(numbers[plow]+numbers[phigh]==target)
        {
            *returnSize=2;
            result[0]=plow+1;
            result[1]=phigh+1;
            return result;
        }
        else if(numbers[plow]+numbers[phigh]<target)
        {
            plow=plow+1;
        }
        else 
            phigh=phigh-1;
    }
    *returnSize=0;
    return result;
    
}
```