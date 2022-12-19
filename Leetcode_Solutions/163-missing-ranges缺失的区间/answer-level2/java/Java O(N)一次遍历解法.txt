### 解题思路
思路非常简单，就是把lower和upper分别加到数组左右，记得将lower和upper转换为long，防止溢出。

### 代码

```java
class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> res = new ArrayList<>();
        long Upper = (long)upper;
        long Lower = (long)lower;
        for (int i = 0; i <= nums.length; i++)
        {
            long right = i < nums.length ? nums[i] : Upper + 1;
            long left = i > 0 ? nums[i-1] : Lower - 1;
            if (right - left > 1)
            {
                if (right - left < 3)
                    res.add(String.valueOf(left+1));
                else
                    res.add(String.valueOf(left+1) + "->" + String.valueOf(right - 1));
            }
        }
        return res;
    }
}
```