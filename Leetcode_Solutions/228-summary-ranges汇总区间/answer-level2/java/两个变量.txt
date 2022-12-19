### 解题思路
两个变量star，end分别记录区间起始，开始时start=end，往后遍历，如果后一个元素 = end + 1，更新end；否则，找到一个区间，然后start和end分别指向下一个数，注意最后要把最后一个区间加上。
### 代码

```java
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        int start = nums[0], end = start;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                // 找到一个
                if (start == end) {
                    res.add(start + "");
                } else {
                    res.add(start + "->" + end);
                }
                start = nums[i];
                end = start;
            }
        }
        // 把最后一个区间加上
        if (start == end) {
            res.add(start + "");
        } else {
            res.add(start + "->" + end);
        }
        return res;
    }
}
```