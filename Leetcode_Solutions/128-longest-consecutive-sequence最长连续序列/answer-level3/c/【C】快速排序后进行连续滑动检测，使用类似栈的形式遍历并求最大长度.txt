1.快速排序
2.遍历
3.查找连续区间求最大的值
```
/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

void quickSort(int *numArray, int left, int right)
{
    if (left >= right) {
        return;
    }

    int i = left;
    int j = right;
    int key = numArray[i];
    while (i < j) {
        while (i < j) {
            if (numArray[j] > key) {
                --j;
            } else {
                numArray[i] = numArray[j];
                break;
            }
        }

        while (i < j) {
            if (numArray[i] <= key) {
                ++i;
            } else {
                numArray[j] = numArray[i];
                break;
            }
        }
    }
    numArray[i] = key;
    if (i - 1 >= 0 && (i - 1) >= left) {
        quickSort(numArray, left, i - 1);
    }
    if (i + 1 <= right) {
        quickSort(numArray, i + 1, right);
    }
}

bool isContinuous(int * numArray, int j, int pre)
{
    return numArray[j] == numArray[pre] + 1;
}

bool isEqual(int * numArray, int j, int pre)
{
    return numArray[j] == numArray[pre];
}

void initialNumArray(int numsSize, int * numArray, int* nums)
{
    for (int i = 0; i < numsSize; ++i) {
        numArray[i] = nums[i];
    }
}

int longestConsecutive(int* nums, int numsSize)
{
    if (nums == NULL) {
        return  0;
    }

    if (numsSize <= 0) {
        return 0;
    }

    int *numArray = (int *)malloc(sizeof(int) * numsSize);
    if (numArray == NULL) {
        return 0;
    }
    initialNumArray(numsSize, numArray, nums);

    quickSort(numArray, 0, numsSize - 1);

    int i = 0;
    int pre = 0;
    int j = 1;
    int length = 1;
    int maxLength = 0;
    while (j < numsSize) {
        if (isContinuous(numArray, j, pre)) {
            ++j;
            ++pre;
            ++length;
        } else if (isEqual(numArray, j, pre)) {
            ++j;
            ++pre;
        } else {
            maxLength = (maxLength > length ? maxLength : length);
            i = j;
            pre = j;
            ++j;
            length = 1;
        }
    }
    maxLength = (maxLength > length ? maxLength : length);
    return maxLength;
}
```
