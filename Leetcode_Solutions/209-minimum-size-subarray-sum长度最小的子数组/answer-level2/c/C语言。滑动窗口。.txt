滑动窗口。sum表示窗口所有值的和。当sum小于s时，sum需要增加，右指针移动。当sum大于等于s时，记录窗口大小，窗口左指针移动。
滑动窗口会遍历所有满足条件子数组，只要记录最小的即可得出结果。

```
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minSubArrayLen(int s, int* nums, int numsSize){
    int i = 0, j = 0, sum = 0, min = 0;
    while(true){
        if(sum < s){
            if(j == numsSize){
                break;
            }
            sum += nums[j++];
        }else{
            if(min == 0){
                min = j - i;
            }
            min = MIN(min, j - i);
            if(min == 1){
                return min;
            }
            sum -= nums[i++];
        }
    }
    return min;
}
```
