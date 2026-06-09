### 解题思路
和三数之和一毛一样

### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int k = 0, i = k + 1, j = nums.length - 1;
        int min = Integer.MAX_VALUE;
        int res = 0;
        for (k = 0; k < nums.length - 2; k++) {
            i = k + 1;
            j = nums.length - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum < target) {
                    int diff = target - sum;
                    if (min > diff) {
                        min = diff;
                        res = sum;
                    }
                    i++;
                } else if (sum > target) {
                    int diff = sum - target;
                    if (min > diff) {
                        min = diff;
                        res = sum;
                    }
                    j--;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
}
```