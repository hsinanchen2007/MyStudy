### 解题思路
只要将数组所有元素疑惑，再将结果和0~numsSize的数疑惑，结果就是没有出现的数
![image.png](https://pic.leetcode-cn.com/4d3874ffc2601f769d22ca687f1a8e6eaa3f7ce606da865ae085b1e449fb9415-image.png)

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int i;
    int rlt = 0;
    for (i = 0; i < numsSize; i++) {
        rlt ^= nums[i];
        rlt ^= i;
    }
    rlt ^= numsSize;
    return rlt;
}
```