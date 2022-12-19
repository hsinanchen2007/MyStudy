### 解题思路
方法一：多指针法
1, iPos_0 指向左边0的位置，遇见0 则加一
2, iPos_2 指向右边2的位置，遇见2 则减一
3, iPos_1 指向中间1的位置，
    遇见0 则和 iPos_0 换位置
    遇见2 则和 iPos_2 换位置
    遇见1 则 加一

### 代码

```c
//方法一：双指针法
void sortColors(int* nums, int numsSize){
    int     iPos_0      = 0;
    int     iPos_2      = numsSize - 1;
    int     iPos_1      = 0;
    int     iTmp        = 0;

    if ((NULL == nums) || (0 == numsSize)) return NULL;
    if (1 == numsSize) return nums;

    while (iPos_1 <= iPos_2)
    {
        if(nums[iPos_0] == 0)
        {
            iPos_0 += 1;
            if (iPos_1 < iPos_0) iPos_1 = iPos_0;
            continue;
        }

        if (nums[iPos_2] == 2)
        {
            iPos_2 -= 1;
            continue;
        }

        if (nums[iPos_1] == 0)
        {
            if (nums[iPos_0] != 0)
            {
                iTmp = nums[iPos_0];
                nums[iPos_0] = nums[iPos_1];
                nums[iPos_1] = iTmp;
            }

            iPos_0 += 1;
            if (iPos_1 < iPos_0) iPos_1 = iPos_0;
            continue;
        }

        if (nums[iPos_1] == 2)
        {
            if (nums[iPos_2] != 2)
            {
                iTmp = nums[iPos_2];
                nums[iPos_2] = nums[iPos_1];
                nums[iPos_1] = iTmp;
            }
            iPos_2 -= 1;
            continue;
        }

        if (nums[iPos_1] == 1)
        {
            iPos_1 += 1;
            continue;
        }
    }
    return nums;
}
```