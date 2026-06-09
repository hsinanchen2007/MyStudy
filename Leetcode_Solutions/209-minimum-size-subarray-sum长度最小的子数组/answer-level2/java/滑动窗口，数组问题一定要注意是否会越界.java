### 解题思路
执行用时 :
2 ms
, 在所有 java 提交中击败了
92.10%
的用户
内存消耗 :
37.5 MB
, 在所有 java 提交中击败了
94.78%
的用户

### 代码

```java
class Solution {
        public int minSubArrayLen(int s, int[] nums) {
            int i = 0, j = 0, n = nums.length;
            int length = Integer.MAX_VALUE;
            if (s == 0 || n == 0) {
                return 0;
            }
            int sum = 0;
            while (i < n && j < n && i <= j) {
                sum = sum + nums[j];
                if (sum >= s) {
                    length = Integer.min(length, j - i + 1);
                    if (length == 1) {
                        return 1;
                    }
                    sum = sum - nums[i++] - nums[j];
                } else {
                    j++;
                }
            }
            return length == Integer.MAX_VALUE ? 0 : length;
        }
    }
```