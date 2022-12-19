### 解题思路
c语言
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.7 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int* result = (int*)calloc((numsSize),sizeof(int));
    int i =0;
    int limit = indexSize*2;
    for(;i<indexSize;i++)
    {
        result[i] = limit;
    }
    i=0;
    int j=i;
    while(i<indexSize){
        if(result[index[i]]<limit){
            j = index[i];
            for(;j<indexSize;j++){
                if(result[j]>=limit)break;
            }
            for(;j>=index[i];j--){
                if(j>0){
                    result[j] = result[j-1];
                }
            }
        }
        result[index[i]] = nums[i];
        i++;
    }
    *returnSize = (numsSize);
    return result;
}
```