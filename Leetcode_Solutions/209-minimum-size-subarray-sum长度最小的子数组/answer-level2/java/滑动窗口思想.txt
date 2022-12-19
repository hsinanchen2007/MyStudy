### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :42.4 MB, 在所有 Java 提交中击败了5.10%的用户
初始化窗口左右边界后，
1.左边界不动，右边界右移，直至窗口内的和sum >= s，再寻找最优值
2.左边界右移，右边界不动，直至不符合sum < s，这时的nums[left]到nums[right]恰好是**以nums[left]开头的符合条件的最短数组子序列**，再移动右窗口，回到步骤1
理解：这样就能得到每个以nums[left]开头的符合条件的数组子序列，再将这些子序列的长度进行比较就能得到最优值
### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int len = nums.length;
        if(len == 0)
            return 0;
        int left = 0, right = 0;
        int sum = 0, ans = 0;
        while(right <= len - 1){
            sum += nums[right++];
            //符合条件，窗口右移，找最优值
            while(sum >= s){
                sum -= nums[left];
                if(ans == 0 || ans > right - left)
                    ans = right - left;
                left++;
            }
        }
        return ans;
    }
}
```