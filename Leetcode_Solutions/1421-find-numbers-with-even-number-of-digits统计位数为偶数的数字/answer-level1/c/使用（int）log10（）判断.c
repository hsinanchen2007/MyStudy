### 解题思路
如果数字为偶数位，（int）log10（）结果则为奇数，将结果%2，如果等于1即可。

### 代码

```c
int findNumbers(int* nums, int numsSize){
    int count = 0;
    int log_result;
    for(int i=0;i<numsSize;i++){
        log_result = (int)log10(nums[i]);
        if(log_result % 2 == 1){
            count += 1;
        }
    }
    return count;
}
```