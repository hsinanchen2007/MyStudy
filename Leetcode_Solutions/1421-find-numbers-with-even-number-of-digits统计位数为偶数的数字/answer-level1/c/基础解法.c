### 解题思路
直接验证每个数字是否为偶数位数
验证方法：除以10，直到商为0，数次数
最直接的算法，效率不是很高但是可算
也可以转化为字符串计数
### 代码

```c
int findNumbers(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i != numsSize;i++)
    {
        int p = nums[i];
        int k = 0;
        while(p!=0)
        {
            p /= 10;
            k++;
        }
        result += (k % 2 == 0) ? 1 : 0;
    }
    return result;
}
```