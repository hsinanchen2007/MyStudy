### 解题思路
题目解析：
  c语言数组里没有直接删除元素的方法。
  题中所谓的“就地删除”，就是说让这个数字不出现就行了。与*删除排序数组中的重复项*题类似。
双指针法：
  1）定义两个指针，一个做遍历元素，一个做存储满足条件元素；
  2）元素不等于val,则存储指针存该元素，两指针都加1；
  3）返回满足条件元素指针

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    for(int j=0; j<numsSize; j++){
        if(nums[j] != val){
            nums[i++] = nums[j];
        }
    }
   
    return i;
}
```