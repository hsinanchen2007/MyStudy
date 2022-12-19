### 解题思路
因为是最小正整数，肯定是从1开始数，代码中minPos就是这个东西
没遍历一个数字，就要看看这个数字是否比你预定的这个正整数的关系，大？小？相等？
我们通过数组的元素交换来达到从某个下标开始都是比minPos的值大的（这个下标代码中是lastGreatPos这个变量），以便于下次我们再次遍历的时候，遍历的数量大大减少
这个算法O（N^2），不过可以通过


### 代码

```c
int firstMissingPositive(int* nums, int numsSize)
{
    int minPos = 1;
    int lastGreatPos = -1;
    for (int i = 0; i < numsSize; i++) {
        int curVal = nums[i];
        if (curVal < minPos) {
            if (lastGreatPos > 0) {
                nums[i] = nums[lastGreatPos];
                lastGreatPos++;
                if (lastGreatPos > numsSize) {
                    break;
                }
            }
        }
        else if (curVal > minPos) {
            if (lastGreatPos < 0) {
                lastGreatPos = i;
            }
        }
        if (minPos == curVal) {
            minPos++;
            if (lastGreatPos > 0) {
                nums[i] = nums[lastGreatPos];
                i = lastGreatPos;
                lastGreatPos++;
                if (lastGreatPos > numsSize) {
                    break;
                }
            } else {
                i = -1;
            }
        }
    }
    return minPos;
}
```