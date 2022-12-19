```java
class Solution {
    // 提升效率的方式，不要直接拼接字符串；
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> ans = new ArrayList<>();
        int N = nums.length;
        // 我们从 lower 开始处理，这里减/加 1 很重要；因为边界是会被包括的，为了和数组保持一致
        long left = (long)lower - 1;
        long right = (long)upper + 1;
        // 对数组元素的判断；
        for (int i = 0; i < N + 1; ++i) {
            StringBuilder str = new StringBuilder();            
            long a2 = 0;
            if (i != N) {
                a2 = nums[i];
            } else {
                a2 = right;
            }
            if (a2 - left > 1) { // 说明有缺失
                long l = left + 1;
                long b = a2 - 1;
                str.append(l);
                if (l != b) {
                    str.append("->");
                    str.append(b);
                }
                ans.add(str.toString());
            }
            left = a2; // 更新下 left;
        }
        return ans;
    }
}
```
