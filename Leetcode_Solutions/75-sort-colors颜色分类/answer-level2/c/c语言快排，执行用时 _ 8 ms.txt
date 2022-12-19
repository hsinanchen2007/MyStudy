### 解题思路
此处撰写解题思路

### 代码

```c

void swap(int* nums, int left, int right)
{
    int temp = 0;
    temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
}


void sortColors(int* nums, int numsSize){
    int len = numsSize;
    if (len < 2) {
        return;
    }
    int zero = 0;
    int two = len;
    int i = 0;
    while (i < two) {
        if (nums[i] == 0) {
            swap(nums, zero, i);
            zero++;
            i++;
        } else if (nums[i] == 1) {
            i++;
        } else {
            two--;
            swap(nums, i, two);
        }
    }
    return;
}

```