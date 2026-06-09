```java
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new ArrayList<>();
        int left = 0;
        int right = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ++right;
            } else {
                StringBuilder builder = new StringBuilder();
                builder.append(nums[left]);
                if (left != right) {
                    builder.append("->");
                    builder.append(nums[right]);
                }
                ans.add(builder.toString());
                ++right;
                left = right;
            }
        }
        if (left < nums.length) {
            StringBuilder builder = new StringBuilder();
            builder.append(nums[left]);
            if (left != right) {
                builder.append("->");
                builder.append(nums[nums.length - 1]);
            }
            ans.add(builder.toString());
        }
        return ans;
    }
}
```
