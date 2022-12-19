
```c
/**
  * -*- coding: utf-8 -*-
  *  @Time    : 2019/8/12 15:19
  *  @Author  : 奥利波德
  *  @FileName: removeElement.c
  *  @Software: CLion
  *  @Blog    ：https://blog.csdn.net/qq_44265507
 */
int removeElement(int* nums, int numsSize, int val){

    int len=0;
    for (int j = 0; j < numsSize; ++j) {
        if(nums[j]!=val){
            nums[len++]=nums[j];
        }
    }
    return len;
}
```


![image.png](https://pic.leetcode-cn.com/8fda9b385df521f14bb07185eb7061cbd23b06dc138e726d4a9f16d1ebf436ca-image.png)
[LeetCode 27 ：移除元素【c语言实现](https://blog.csdn.net/qq_44265507/article/details/99305869)
