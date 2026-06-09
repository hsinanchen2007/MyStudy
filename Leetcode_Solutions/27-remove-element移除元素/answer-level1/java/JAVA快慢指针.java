### 解题思路
![1.png](https://pic.leetcode-cn.com/4d3aa2d981e242589478140096d861f2b43eb60e5984c13b58d2868a80cc25c4-1.png)

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums.length == 0) return 0;
        int slow = 0;
        for (int fast = 0; slow < nums.length; slow++, fast++){
            while(fast < nums.length && nums[fast] == val){
                fast++;
            }
            if (fast >= nums.length) break;
            nums[slow] = nums[fast];
        }
        return slow;
    }
}
```