先创建了一个位置数组，数组的每个元素对应num的最后位置。
然后每插入一个新的数字，在新数字的位置后面的数字都要往后移动一个位置，相当于位置数组中大于等于该位置的元素+1
最后再根据位置数组将num排序组成最后的结果

```
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    * returnSize = numsSize;
    int *pos = malloc(sizeof(int) * numsSize);
    int *res = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(pos[j] >= index[i])
                pos[j]++;
        }
        pos[i] = index[i];
    }
    for(int i = 0; i < numsSize; i++)
    {
        res[pos[i]] = nums[i];   
    }
    return res;
}
```
