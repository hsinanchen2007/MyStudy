

```
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    int mov_num = 0;//记录前移的步数
    int i = 0;
    for (; i < numsSize-1; ++i) {
        if (nums[i] == nums[i+1]) ++mov_num;
        else nums[i-mov_num] = nums[i];
    }
    nums[i-mov_num] = nums[i];  //处理尾部节点
    return (numsSize - mov_num);
}
```
