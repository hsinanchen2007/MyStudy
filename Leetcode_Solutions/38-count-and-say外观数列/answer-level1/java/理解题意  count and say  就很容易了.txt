>这道题一开始感觉有点绕，不过理解了之后就容易了，说白了就是下一个数的表示结果是上一个数`say`出来的结果
 比如：
- 首先`1`，自然表示为`1`，而`say`出来就是`1`个`1`,
- 所以`2`应该表示为`11`，而`say`出来就是`2`个`1`，
- 所以`3`应该表示为`21`，而`say`出来就是`1`个`2`，`1`个`1`，
- 所以`4`应该表示为`1211`，以此类推...

```java
class Solution {
    public String countAndSay(int n) {
        if (n <= 0) {
            return "";
        }
        String[] seq = new String[n];
        seq[0] = "1";
        for (int i = 1; i < n; i++) {
            seq[i] = convert(seq[i - 1]);
        }
        return seq[n - 1];
    }

    public String convert(String str) {
        StringBuilder ans = new StringBuilder();
        int count = 1;
        for (int i = 0; i < str.length(); i++) {
            // 这一部分是"count", 记录连续出现x个y
            if (i < str.length() - 1 && str.charAt(i) == str.charAt(i + 1)) {
                count++;
            } else {
            // 这一部分是"say"，将上面"count"的结果"xy"作为下一个数的一部分（若上面记录到2个1，就拼接"21"）
                ans.append(count).append(str.charAt(i));
                count = 1;
            }
        }
        return new String(ans);
    }
}
```
