### 解题思路
1. 简单粗暴的方法2ms
2. 首先从前往后第一个逆序的数，假定是左边界。然后继续往后找小于左边界的最小值。拿着最小值去左边界前面找，看是否有大于它的值。如果有，大于它的值的小标为真正左边界。
3. 寻找右边界同上。
4. 返回right-left+1.
5. 记着处理特殊情况，如全顺序，或全逆序。

### 代码

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int length = nums.length, right = -1, left = -1, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length-1; i++)
            if(nums[i] > nums[i+1]){
                left = i;
                min = nums[i];
                break;
            }
        if(left == -1) return 0;
        for(int i = left + 1; i < nums.length; i++)
            if(nums[i] < min) min = nums[i];
        for(int i = 0; i < left; i++) if(nums[i] > min) left = i;
        for(int i = nums.length-1; i > 0; i--)
            if(nums[i] < nums[i-1]){
                while(i < length - 1 && nums[i] == nums[i+1]) i++;
                right = i;
                max = nums[i];
                break;
            }
        if(right == -1) return length;
        for(int i = right - 1; i >= 0; i--)
            if(nums[i] > max) max = nums[i];
        for(int i = length-1; i > right; i--) if(nums[i] < max) right = i;
        return right - left + 1;

    }
}
```