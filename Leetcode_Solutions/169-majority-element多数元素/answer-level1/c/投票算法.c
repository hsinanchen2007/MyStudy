### 解题思路
简单来说就是对每个数字计算出现次数，相同加一，不相同减一，减到0了就换一个数开始计算出现次数；众数（出现册数超过1/2）的数一定会被留到最后，因为没有其他数字出现的次数比它多。

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int candidate = nums[0], count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (candidate == nums[i]) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}
```