### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMaximumXOR(int[] nums) {
        int n = nums.length;
        int ans = Integer.MIN_VALUE;
        // if(n == 1) return 0; // 只有一个元素的话，异或值为0
        for(int i = 0; i < n -1; i++) {
            for(int j = i + 1; j < n; j++) {
                int res = nums[i] ^ nums[j];
                ans = Math.max(res, ans);

            }
        }
        return ans == Integer.MIN_VALUE ? 0: ans; 

    }
}
```