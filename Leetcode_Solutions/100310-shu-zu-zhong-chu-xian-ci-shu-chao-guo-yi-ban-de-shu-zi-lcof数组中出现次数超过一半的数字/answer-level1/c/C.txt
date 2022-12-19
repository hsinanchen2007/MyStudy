### 解题思路
开始用的排序 求中间值，  然后参考了大神们的思路 翻译成C语言

### 代码

```c

int majorityElement(int* nums, int numsSize){
    int num = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            num = nums[i];
        } 
        if (num == nums[i]) {
            count++;
        } else {
            count--;
        }
    }

    return num;
}
```