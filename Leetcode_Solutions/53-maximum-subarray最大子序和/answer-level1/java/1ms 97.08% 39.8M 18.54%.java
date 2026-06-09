### 解题思路
设定滑动指针，以及当前累加值，当累加值不大于0时，
前一组数据已无意义，则从下个坐标开始计算下一组值
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 0) return 0;
        int max = Integer.MIN_VALUE;
        int current = 0;
        int right = 0;
        while(right<nums.length){
            current = current + nums[right++];
            max = Math.max(max,current);
            if(current<=0){
                //当本次加法，已经结果为0 则从下一个作为开始重新计算下一组值
                current = 0;
                continue;
            } 
        }
        return max;
    }
}
```