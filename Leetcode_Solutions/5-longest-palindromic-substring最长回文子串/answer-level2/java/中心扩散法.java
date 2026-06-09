### 解题思路
中心扩散法
假定每个数组下标和下边中间的位置，都是回文子串的中心点，进行扩散，看哪个位置扩散的根源
#### 总共中心点数目
2n - 1
1. 数组下标位置扩散，那么回文子串长度为奇数，eg：aba
2. 数组两个下标位置中间扩散，那么回文子串产出为偶数，eg：abba
#### 时间复杂度
外层结构时间频率为T(2n)，时间复杂度为O(n)
但是考虑内部最坏的情况，eg："aaaaaaaaaaaaaaaaa"
以"aaa"做说明（n=3）
第一次  第二次  第三次
a       aaa   a
aa       aa
时间频率：2n + n的平方
所以，最终得出时间复杂度为：O(n的平方)
### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return "";
        }
        int start = 0, end = 0;
        int maxln = 0;
        for (int i = 0; i < s.length(); i++) {
            int ln1 = geiLengthByCenter(s, i, i);
            int ln2 = geiLengthByCenter(s, i, i + 1);
            int tln = Math.max(ln1, ln2);
            if (tln > (end - start + 1)) {
                start = i - ((tln - 1) / 2);
                end = i + (tln / 2);
            }
        }
        return s.substring(start, end + 1);
    }

    public static int geiLengthByCenter(final String s, int l, int r) {
        int ll = l, rr = r;
        while (ll >= 0 && rr < s.length()
                && s.charAt(ll) == s.charAt(rr)
        ) {
            ll--;
            rr++;
        }
        // 这里要减去1，而不是 + 1，是因为ll和rr在最后的正确结果之后，额外的--和++了
        return rr - ll - 1;
    }
}
```