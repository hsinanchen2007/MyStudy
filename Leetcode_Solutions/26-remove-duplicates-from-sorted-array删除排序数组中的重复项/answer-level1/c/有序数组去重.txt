### 解题思路
在原有序数组上进行排重，并返回数组长度。

#### 双指针法

使用两个计数器，分别记录当前未重复的最后一位的下标（current），和滑块下标依次遍历整个数组（slide）。当slide位置上的元素与current上不同时，slide不断后移，直到找到不等于current的元素，然后将current+1位置上的值替换为slide上的值。直到整个数组遍历完毕，current是最后一位的下标，所以数组长度等于current+1。
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if (numsSize < 0) return 0;
    if (numsSize <= 1) return numsSize;
    
    int current = 0;
    int slide = 1;
   
    while (slide < numsSize){
        if (nums[slide] != nums[current]) {
            nums[current+1] = nums[slide];
            current+=1;
        }
        slide++;
    }
    return current+1;

}
```