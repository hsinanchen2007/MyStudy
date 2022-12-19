### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return nums;
        }
        int[] res = new int[nums.length - k + 1];
        res[0] = nums[0];
        for(int i = 0; i < k; i++) {
            if (nums[i] > res[0]) {
                res[0] = nums[i];
            }
        }
        int i = 1;
        for (int left = 0, right = k; right < nums.length; left++, right++) {
            res[i] = nums[right];
            if (nums[left] < res[i - 1]) {
                res[i] = nums[right] > res[i - 1] ? nums[right] : res[i - 1];
            } else {
                for (int j = left + 1; j < right; j++) {
                    res[i] = nums[j] > res[i] ? nums[j] : res[i];
                }
            }
            i++;
        }
        return res;
    }
}
```