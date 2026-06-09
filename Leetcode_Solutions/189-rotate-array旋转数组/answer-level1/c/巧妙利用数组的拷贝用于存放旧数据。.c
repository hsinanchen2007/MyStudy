### 解题思路
![image.png](https://pic.leetcode-cn.com/67f467c08e50059c2190a5b3f1ec96b49707f22ec6cf2dd2cf4b351d8468d8a5-image.png)


### 代码

```c
void rotate(int* nums, int numsSize, int k){
    if(NULL == nums || 0 == numsSize)
    {
        return;
    }
    
    int a[numsSize];

    for(int i = 0 ;i < numsSize;i++)
    {
        a[i] = nums[i]; 
    }

    for(int i = 0 ;i < numsSize;i++)
    {
        nums[(i+ k)%numsSize] = a[i]; 
    }
}
```