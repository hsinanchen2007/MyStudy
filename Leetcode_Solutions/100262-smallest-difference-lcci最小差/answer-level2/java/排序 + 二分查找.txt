# 代码
顺带一提，官方总喜欢用`Integer.MAX_VALUE` 或 `Integer.MIN_VALUE`来恶心人。

```java
class Solution {
    public int smallestDifference(int[] a, int[] b) {
        Arrays.sort(a);
        Arrays.sort(b);
        int res = Integer.MAX_VALUE, len = b.length;
        for (int num_a : a) {
            int idx = Arrays.binarySearch(b, num_a);
            //能在b数组中找到值为num_a的数
            if (idx >= 0) return 0;
            idx = -idx - 1;
            if (idx > 0) {
                int diff = num_a - b[idx - 1];
                if (diff > 0)
                    res = Math.min(res, num_a - b[idx - 1]);
            }
            if (idx < len) {
                int diff = b[idx] - num_a;
                if (diff > 0)
                    res = Math.min(res, b[idx] - num_a);
            }
        }
        return res;
    }
}
```
