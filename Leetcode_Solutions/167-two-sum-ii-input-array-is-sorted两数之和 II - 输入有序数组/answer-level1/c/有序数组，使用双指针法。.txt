### 解题思路
![image.png](https://pic.leetcode-cn.com/8b93c6b1d9cafa601d0bf3094fa5a55ae4b507f6de0ec2f53ddaa96be8447423-image.png)


此处撰写解题思路
1）有序数组，使用双指针法，好过暴力枚举
2）我没想到怎么用二分查找，看了后面的题解，从左到右遍历，首先确定一个值，然后二分查找另外一个值。
3）这道题目我没用到二分查找，抱歉。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int index1 = 0;
    int index2 = numbersSize - 1;

    while (numbers[index1] + numbers[index2] != target) {
        if (numbers[index1] + numbers[index2] > target) {
            index2--;
            continue;
        }
        if (numbers[index1] + numbers[index2] < target) {
            index1++;
        }
    }

    int *res = calloc(2, sizeof(int));
    res[0] = index1 + 1;
    res[1] = index2 + 1;
    *returnSize = 2;

    return res;
}
```