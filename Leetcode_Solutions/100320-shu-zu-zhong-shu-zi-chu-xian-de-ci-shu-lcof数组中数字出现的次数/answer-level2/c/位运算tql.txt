### 解题思路
利用异或运算`^`的特点
  1. 0和任何数异或等于该数
  2. 任何数和自身异或等于0
  3. 异或运算满足交换律

  当将一个数组的数全部按位异或后，可以将成对的数放在前面先运算，而成对的数经过上述1,2会得到0，也就达到了消去成对的数的目的。

  此时数组中剩下两个不同的数异或，得到的结果`mask`是这两个数不同的位上值为1，相同的为0.

但这样没办法把两个数分离出来。既然这两个不同的数必然有位是不同的，并且异或的结果也告诉我们哪些位不同。我们不妨以`mask`的最低的值为1的位（设为a0位）来区分这两个数，其中一个数a0位等于1，另一个等于0.

  其中通过位运算`x & (-x)`得到a0 = 1，其他位为0的结果。

  同样我们将数组中其他的数，也分成两组：a0 = 0组和a0 = 1组，这样保证了两个不同的数分在两组，也保证了成对的数必在其中一组而不会一对数分在两组。

  再分别对两组的数进行异或运算，最后得到的两个数即所求。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize){
    int mask = 0;
    int i;
    for(i = 0; i < numsSize; i++)
    {
        mask ^= nums[i];
    }
    mask = mask & (-1*mask);
    int m1 = 0, m2 = 0;
    for(i = 0; i < numsSize; i++)
    {
        if((nums[i] & mask) == 0)//位运算优先级低于关系运算
        {
            m1 ^= nums[i];
        }
        else
        {
            m2 ^= nums[i];
        }
    }
    *returnSize = 2;
    int *a = (int *)malloc(2*sizeof(int));
    a[0] = m1;
    a[1] = m2;
    return a;
}
```