### 解题思路
给大家提供一个小思路，希望大家在使用指针的时候一定要注意判空，在此感谢@铠皇在线大刀砍题帮助我找到bug，再次感谢。

### 代码

```c
int removeDuplicates(int* nums, int numsSize)
{
    if (nums == NULL || !numsSize) return 0; 
    int num = *nums, count = 1; 
    for (int* p = nums; p != nums + numsSize; p++) {
        if (*p != num) { 
            num = *p;
            *(nums+count) = num;
            count++;
        }
    }
    return count; 
}
```