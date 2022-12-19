### 解题思路
此处撰写解题思路

执行用时 :96 ms, 在所有 C 提交中击败了31.06%的用户
内存消耗 :7.8 MB, 在所有 C 提交中击败了100.00%的用户

方法一和方法二思路整体相似，但是实现略有不同

方法一：
（1）依次求出0到i的数组和；
（2）移动左指针，直至符合条件

### 代码

```c
bool checkSubarraySum(int* nums, int numsSize, int k){
    int left, right, temp;
    int *sum = NULL;

    if (nums == NULL || numsSize <= 1) {
        return false;
    }

    sum = (int *)malloc(sizeof(int) * numsSize);
    sum[0] = nums[0];

    for (left = 1; left < numsSize; left++) {
        sum[left] = nums[left] + sum[left - 1];
    }

    for (left = 0, right = 0; right < numsSize; right++) {
        temp = sum[right];

        while (left <= right && right - left >= 1) {
            if (temp == k || (k != 0 && temp % k == 0)) {
                return true;
            } else {
                temp -= nums[left++];
            }
        }
        left = 0;
    }
    free(sum);
    return false;
}

```


方法二：


### 代码

```c
bool checkSubarraySum(int* nums, int numsSize, int k){
    int *sum = (int *)malloc(sizeof(int) * numsSize);

    sum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum[i] = sum[i - 1] + nums[i];
    }
        
    for (int start = 0; start < numsSize - 1; start++) {
        for (int end = start + 1; end < numsSize; end++) {
            int summ = sum[end] - sum[start] + nums[start];
            if (summ == k || (k != 0 && summ % k == 0)) {
                return true;
            }
        }
    }
    return false;
}
```