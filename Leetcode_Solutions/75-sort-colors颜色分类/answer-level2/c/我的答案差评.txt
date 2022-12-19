### 解题思路
此处撰写解题思路

### 代码

```c
void sortColors(int* nums, int numsSize){
    int cnt0, cnt1, cnt2;
    cnt0 = cnt1 = cnt2 = 0;

    for (int i = 0; i < numsSize; i++) {
        nums[i] == 0 ? cnt0++ : cnt0;
        nums[i] == 1 ? cnt1++ : cnt1;
        nums[i] == 2 ? cnt2++ : cnt2;
    }

    for (int i = 0; i < cnt0; i++) {
        nums[i] = 0;
    }

    for (int i = cnt0; i < cnt1 + cnt0; i++) {
        nums[i] = 1;
    }

    for (int i = cnt1 + cnt0; i < numsSize; i++) {
        nums[i] = 2;
    }

    return nums;
}
```