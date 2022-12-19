### 解题思路
解题思路见注释

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        // 暴力解法遍历整个数组
        // 改进的解法为二分查找,检查middle两侧的数是否连续
        // 其中要考虑三种情况，缺失的数字在第一个，中间，尾巴上
        int head = 0;
        int tail = nums.length - 1;
        int middle = (head + tail) / 2;
        while(head <= tail){
            // 二分查找的目的是找出nums[middle] != middle且nums[middle - 1] == midlle -1
            // 如果nums[middle] == middle则说明前面middle个数字排列没问题,从后半部分找
            if(nums[middle] == middle){
                head = middle + 1;
            }else{
                if(middle > 0 && nums[middle - 1] != middle - 1){
                    tail = middle - 1;
                }else{
                    return middle;
                }  
            }
            middle = (head + tail) / 2;
        }
        // 如果数组中的数字排序没问题，也就是最后一个数字等于nums.length-1，则缺失的数字为nums.length
        return nums.length;
    }
}
```