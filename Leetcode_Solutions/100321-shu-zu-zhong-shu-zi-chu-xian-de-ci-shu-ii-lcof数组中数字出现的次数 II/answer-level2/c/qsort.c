### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a3278207172d2716805c9da5bcfe09dc48e47debb32826f80d88d23dfbeacb8c-image.png)
1)这道题目，最直观就是 hash表，无奈c语言没有hash表，很大范围的话，没有map是玩不转的
2)位运算，这个玩法我没掌握，那就只有qsort，然后判断了。
### 代码

```c
int cmp(const void *a, const void *b)
{
    long num1 = *(int*)a;
    long num2 = *(int*)b;
    return num1 - num2;
}

int singleNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int i;

    if (numsSize == 1) {
        return nums[0];
    }
    if (nums[0] != nums[1]) {
        return nums[0];
    }
    if (nums[numsSize - 1] != nums[numsSize - 2]) {
        return nums[numsSize - 1];
    }
    for (i = 3; i < numsSize - 2; i += 3) {
        if (nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
            return nums[i];
        }
    }

    return 0;
}
```