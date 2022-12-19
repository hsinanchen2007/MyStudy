### 解题思路
利用两个相同的数求异或（^）会变为0，而0与任何数m求异或都是m。那么将数列从头至尾、0~numsSize（让存在的数字能出现第二遍）取异或，最后的结果一定是缺失的数。



### 代码

```c
int missingNumber(int* nums, int numsSize){
    if (!nums || !numsSize)  return 0;
    int ans = nums[0];
    ans ^= 0;
    ans ^= numsSize;
    for (int i = 1; i < numsSize; i++) {
        ans ^= nums[i];
        ans ^= i;
    }
    return ans;
}
```