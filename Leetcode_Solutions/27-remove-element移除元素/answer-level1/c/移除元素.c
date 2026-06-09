### 解题思路
第一种方法使用插入法，统计与给定值不相等元素个数。
第二种方法统计与给定值相等元数的个数n，当不等时前移n位，最后用原数组长度-n得到移除元数之后数组的长度。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    if(numsSize == 0) return numsSize;
    int n = 0;
    // 第一种方法
    for(int i = 0; i<numsSize; i++){
        if(nums[i] != val){
            nums[n++] = nums[i];
        }
    }
    return n;
    // 第二种方法
    // for(int i = 0; i<numsSize; i++)
    //     if(nums[i] != val) {
    //         nums[i-n] = nums[i];
    //     } else {
    //         n++;
    //     }
    // return numsSize - n;
}
```