### 解题思路
![image.png](https://pic.leetcode-cn.com/3ca6fb29173c2b011ec4c56e1200392eb214c78da29a5a3994312305e78790c3-image.png)


### 代码

```c
int singleNumber(int* nums, int numsSize){
    if(NULL == nums || 0 == numsSize)
    {
        return 0;
    }

    int ans = 0;

    for(int i = 0;i < numsSize ;i++)
    {   
        ans ^= nums[i];
    }

    return ans;
}
```