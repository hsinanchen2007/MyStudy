线性扫描
```java
class Solution {
    private static class Tuple {
        int prev;
        int next;
    }
    public int uniqueLetterString(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        // 维护prev数组保存该字母的前一出现位置
        int[] prev = new int[26];
        // 保存s中位置i上字母的前一出现位置（前驱）和后一出现位置（后继）
        // 即在tuples[i].prev, i, tuples[i].next位置上的字母相同
        Tuple[] tuples = new Tuple[s.length()];
        // 初始化
        for (int i = 0; i < s.length(); i++) {
            tuples[i] = new Tuple();
        }
        for (int i = 0; i < 26; i++) {
            prev[i] = -1;
        }
        // 填充tuples
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'A';
            // 更新当前字母的前驱和后继
            tuples[i].prev = prev[c];
            tuples[i].next = s.length();
            // 更新前一相同字母的后继
            if (prev[c] >= 0) {
                tuples[prev[c]].next = i;
            }
            // 更新字母s[i]的前一出现位置为i，以便后续使用
            prev[c] = i;
        }
        long ans = 0;
        // 分别计算仅包含一个s[i]的子串个数，累加起来就是所要求的结果
        for (int i = 0; i < s.length(); i++) {
            ans += (i - tuples[i].prev) * (tuples[i].next - i);
        }
        return (int) (ans % 1_000_000_007);
    }

}


```
