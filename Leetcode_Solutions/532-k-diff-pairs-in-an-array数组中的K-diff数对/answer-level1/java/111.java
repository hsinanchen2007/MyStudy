### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findPairs(int[] nums, int k) {
        if (nums == null || nums.length <= 1) {
            return 0;
        }
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            // 保证每次都是不同的起始点
            while (i > 0 && i < nums.length - 1 && nums[i] == nums[i - 1]) {
                i++;
            }
            if (i == nums.length - 1) {
                break;
            }
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] - nums[i] == k) {
                    ans++;
                    break;
                } else if (nums[j] - nums[i] > k) {
                    break;
                }
            }
        }
        return ans;        
    }
}
```