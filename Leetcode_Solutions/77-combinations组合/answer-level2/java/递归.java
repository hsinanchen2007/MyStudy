### 解题思路

本题可以使用递归来实现

![image.png](https://pic.leetcode-cn.com/69909f2bde6061e87226be56c6dbdf988190b69bf17573809585bc17d6aa1af6-image.png)

### 代码

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        if (n < k) return Collections.emptyList();
        List<List<Integer>> result = new ArrayList<>();
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                List<Integer> item = new ArrayList<>();
                item.add(i);
                result.add(item);
            }
            return result;
        }

        result.addAll(combine(n - 1, k));
        for (List<Integer> item : combine(n - 1, k - 1)) {
            item.add(n);
            result.add(item);
        }
        return result;
    }
}
```