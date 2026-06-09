### 解题思路
执行用时 :
2 ms
, 在所有 Java 提交中击败了
89.46%
的用户

### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        if (nums == null) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = 0;
        while (right < nums.length) {
            if (sum < s) {
                sum += nums[right];
            }
            while (sum >= s) {
                if(minLen == 0) {
                    minLen = right - left + 1;
                } else {
                    minLen = Math.min(minLen, right - left + 1);
                }
                
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return minLen;
    }
}
```