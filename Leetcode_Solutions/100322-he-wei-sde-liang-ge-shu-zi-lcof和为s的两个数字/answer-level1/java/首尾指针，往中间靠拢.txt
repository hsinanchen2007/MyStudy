### 复杂度分析
时间复杂度：O(n)
空间复杂度：O(1)

### 解题思路
由于数组按递增排列，因此可以用两个指针往中间靠拢的方法解答
设头尾指针分别指向数组首尾元素，即较小值与较大值
若 sum 大于 target，则将较大值减小，即尾指针左移
反之，首指针右移

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {

        int i = 0;
        int j = nums.length - 1;

        int[] ans = new int[2];
        int[] empty = new int[]{};

        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum > target) {
                j--;
            } 
            else if (sum < target) {
                i++;
            }
            else {
                ans[0] = nums[i];
                ans[1] = nums[j];
                return ans;
            }
        }
        return empty;
    }
}
```