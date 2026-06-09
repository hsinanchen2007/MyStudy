### 解题思路
执行用时 0ms，内存消耗 33.9MB

与官方解法思路相同。

问题是当前的房间到底抢不抢。
如果抢，那么最大的数额就是上上个房间时能抢到的最大数额和本房间的数额之和。
如果不抢，那么最大数额就是上一个房间的最大数额。
本房间的最大数额是抢与不抢本房间两种情况的最大值。

对数组本身进行修改，把nums[i]的值赋值为当前最大值，减少内存消耗。
因为在nums[i]时需要考虑nums[i-2]的值，将数组长度为0和1时的判断和nums[1]的赋值放在循环外。
与官方解法相比，多了判断，少了两个变量，基本没啥区别。

菜鸡之见，欢迎大佬来讨论留言。
### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0)
            return 0;
        
        if (nums.length == 1)
            return nums[0];
       
        nums[1] = Math.max(nums[0],nums[1]);

        for(int i=2;i<nums.length;i++){
            nums[i] = Math.max(nums[i-2]+nums[i],nums[i-1]);
        }
        return nums[nums.length-1];
    }
}
```