**方法一**
用slow-1指针指向的数字和fast指针指向的数字进行比较。

如果数字不同，说明slow-1与fast指针指向的数字不同，slow指向的数字可能与slow-1相同，slow指向的数字也可能与fast指向的数字相同，也可能三者均不同。
则将fast指针指向的数字赋值给slow指针指向的下一个位置。

如果数字相同，则说明slow-1,slow,fast指针指向的是三个相同的数字，因此不能在此处给slow+1赋值。

**方法二**
用slow指针指向的前两个数字和fast指针指向的数字进行比较。

如果数字不同，说明slow-2与fast指针指向的数字不同，slow-1指向的数字可能与slow-2相同，slow-1指向的数字也可能与fast指向的数字相同，也可能三者均不相同。
则将fast指针指向的数字赋值给slow指针指向的位置。

如果数字相同，则说明slow-2,slow-1,fast指针指向的是三个相同的数字，因此不能在此处给slow赋值。

```
//方法一
int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2)
        return numsSize;
    int slow = 1, fast = 2;
    int max = 2;
    while (fast < numsSize) {
        if (nums[slow - max + 1] != nums[fast]) {
            ++slow;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}

//方法二
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2)
        return numsSize;
    int slow = 2, fast = 2;
    int max = 2;
    while (fast < numsSize) {
        if (nums[slow - max] != nums[fast]) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;   
    }
    return slow;
}
```
