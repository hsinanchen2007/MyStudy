### 解题思路
C语言小白解法：
遍历一遍数组，找出最大值和次大值。然后比较。。。

### 代码

```c
int dominantIndex(int* nums, int numsSize){
    int Fst = -1;int Sec = -1;int index = 0;
    for (int i = 0;i < numsSize;i++)
    {
        if (nums[i] > Fst)
        {
            Sec = Fst;
            Fst = nums[i];
            index = i;
        }
        else if (nums[i] > Sec)
        {
            Sec = nums[i];
        }
    }
    return Fst>=Sec*2 ? index:-1;
}
```