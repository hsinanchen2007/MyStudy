### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        Map<Integer, Integer> count = s.chars().boxed()
            .collect(Collectors.toMap(k -> k, v -> 1, Integer::sum));

        int ans = count.values().stream().mapToInt(v -> v / 2 * 2).sum();
        return ans < s.length() ? ans + 1 : ans;
    }
}
```