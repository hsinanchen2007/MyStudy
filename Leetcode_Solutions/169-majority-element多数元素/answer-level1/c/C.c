### 解题思路
直接上代码

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int ret = nums[0];
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            ret = nums[i];
        }
        if (nums[i] == ret) {
            count++;
        } else {
            count--;
        }
    }
    return ret;
}
```