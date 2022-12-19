### 解题思路
利用是排序数组，遇到不同肯定是新的元素
遍历一遍所有不同即可

### 代码

```c

int removeDuplicates(int* nums, int numsSize){

    int i=0,k=1;

    if(numsSize ==0 )
        return 0;

    for(i=1;i<numsSize;i++){
        if(nums[i] != nums[i-1]){
            nums[k++] = nums[i];
        }
    }
    return k;
}
```