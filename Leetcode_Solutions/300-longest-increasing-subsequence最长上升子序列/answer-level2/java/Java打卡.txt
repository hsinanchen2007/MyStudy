### 解题思路
Java打卡

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        int n = nums.length;
        int[] top = new int[n];
        int piles = 0;
        for (int i = 0; i < n; i++) {
            int poker = nums[i];
            int left = 0;
            int right = piles;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (top[mid] > poker) {
                    right = mid;
                } else if (top[mid] < poker) {
                    left = mid + 1;
                } else if (top[mid] == poker) {
                    right = mid;
                }
            }
            
            if (left == piles) {
                piles += 1;
            }
            
            top[left] = poker;
        }
        
        return piles;
        
    }
}
```