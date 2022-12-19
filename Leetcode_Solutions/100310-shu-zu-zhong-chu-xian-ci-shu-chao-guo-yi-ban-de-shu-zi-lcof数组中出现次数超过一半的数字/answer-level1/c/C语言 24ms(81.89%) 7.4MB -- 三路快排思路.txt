### 解题思路
官方答案的摩尔投票法肯定是最佳解法，但是估计大家一般都想不到，这里给出一个相对普通点的思路
三路快排适合重复元素较多的场景，我们在每次三路快排后考虑划分好的三路哪路超过总长度一半，如果是相同值的那路就已经找到答案了，如果不是，相应更新快排的左/右界，重新做下一次快排，直到找到为止。
在快排前先做了个nums[left], nums[(left+right)/2], nums[right]取中位数当标的的步骤，减少了近一半的整体运行时间。

### 代码

```c
void inline swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void median(int *nums, int left, int right) {
    if (left < right - 1) {
        int a = left;
        int b = (left + right)/2;
        int c = right;

        int max = c;
        if (nums[b] > nums[max]) {
            max = b;
        }
        if (nums[a] > nums[max]) {
            max = a;
        }
        if (max != c) {
            swap(&nums[max], &nums[c]);
        }
        if (nums[a] < nums[b]) {
            swap(&nums[a], &nums[b]);
        }
    }
}

int majorityElement(int* nums, int numsSize){
    if (!nums) {
        return -1;
    }

    int left, right;
    left = 0;
    right = numsSize - 1;

    int i, l, r, pivot;
    while (right - left >= numsSize/2) {
        median(nums, left, right);

        i = left;
        l = left;
        r = right;
        pivot = nums[i];

        while (i <= r) {
            if (nums[i] < pivot) {
                swap(&nums[l], &nums[i]);
                l++;
                i++;
            }
            else if (nums[i] > pivot) {
                swap(&nums[i], &nums[r]);
                r--;
            }
            else {
                i++;
            }
        }

        if (r - l + 1 > numsSize/2) {
            return nums[l];
        }
        else if (l - left > numsSize/2) {
            right = l - 1;
        }
        else {
            left = r + 1;
        }
    }

    return -1;
}
```