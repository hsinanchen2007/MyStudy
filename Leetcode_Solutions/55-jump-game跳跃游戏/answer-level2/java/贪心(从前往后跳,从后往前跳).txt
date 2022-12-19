## 思路:

贪心算法

思路一:

从前往后跳

思路二:

从后往前推

------

[45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)一样的,

[[解题链接]45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)



## 代码:







思路一:



```python [1]
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        start = 0
        end = 0
        n = len(nums)
        while start <= end and end < len(nums) - 1:
            end = max(end, nums[start] + start)
            start += 1
        return end >= n - 1
```



```java [1]
class Solution {
    public boolean canJump(int[] nums) {
        int start = 0;
        int end = 0;
        while (start <= end && end < nums.length - 1) {
            end = Math.max(end, nums[start] + start);
            start++;
        }
        return end >= nums.length-1;
    }
}
```

思路二



```python [2]
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        #start = 0
        n = len(nums)
        start = n - 2
        end = n - 1
        while start >= 0:
            if start + nums[start] >= end: end = start
            start -= 1
        return end <= 0
```



```java [2]
class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int start = n - 2;
        int end = n - 1;
        while (start >= 0) {
            if (start + nums[start] >= end) end = start;
            start--;
        }
        return end <= 0;
    }
}
```

