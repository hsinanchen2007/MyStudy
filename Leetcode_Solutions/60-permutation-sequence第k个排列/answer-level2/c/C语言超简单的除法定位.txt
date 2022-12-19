![Screenshot from 2020-03-30 20-33-25.png](https://pic.leetcode-cn.com/622711697dc9e5e3412895467fa7b32aa9f0e856d108e87f8c996ff768554810-Screenshot%20from%202020-03-30%2020-33-25.png)

例如：  n = 6, k = 373
初始化数组 nums = [1, 2, 3, 4, 5, 6];
首先应该明白，以 1 开头的全排列有 5! 个，以 2 开头的全排列有 5! 个 …… 共 5! * 6 = 6! 个；
1. 故 k = 373 时，全排列的第一个数字应该是 nums[ k / 5! ] = 4 ;
2. 数组删除 4, 此时 nums = [1, 2, 3, 5, 6]; k %= 5! = 12 ; 
3. 接下来就是在 nums 中找第 12 个全排列，重复 1，2 步即可 。


> 注意数组下标是从 0 开始，k 首先要减去 1 


```c
int factorial(int n)
{
    int num = 1;
    while (n > 0)
    {
        num *= n;
        n--;
    }
    return num;
}
void deleteItem(int *nums, int numsSize, int in)
{
    for (; in < numsSize - 1; in++)
        nums[in] = nums[in + 1];
}
char *getPermutation(int n, int k)
{
    int i, j = 0, nums[n], factor;
    char *res = (char *)malloc(sizeof(char) * 10);
    for (i = 1; i <= n; i++) //初始化一个 1-n的数组
        nums[i - 1] = i;
    for (i = 0,k--; i < n; i++) //k要先减去1
    {
        factor = factorial(n - i - 1);
        res[j++] = nums[k / factor] + '0';
        deleteItem(nums, n - i, k / factor); //取出一个元素
        k %= factor;
    }
    res[j] = '\0';
    return res;
}
```
