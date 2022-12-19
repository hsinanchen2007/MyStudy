### 解题思路
![image.png](https://pic.leetcode-cn.com/d33118721b5a330120850b4e22b10dd340026ce3a530f684fec8ec7383e26aa3-image.png)


### 代码

```c
int singleNumber(int* nums, int numsSize){
    int a = 0;
    int b = 0;

    for(int i = 0;i < numsSize;i++)
    {
        b = (b ^ nums[i]) & ~a;
        a = (a ^ nums[i]) & ~b;
    }

    return b;
}
```