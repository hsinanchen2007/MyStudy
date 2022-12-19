简单来说：求最长回文子串。有一个破题点！
破题点就是：回文子串肯定有个对称中心点。
举例1："aba"   中心点就是b所在的位置。index=1。value='b'
举例2: "abba"  这时中心点变成了虚无的值，即可以理解为"bb"就是中心点。也就是说index为1和2。value='bb'

因此这题需遍历一遍字符串s, 对s中每个char值为基点进行上述两个例子情况进行遍历。最终便可拿到结果。

看具体代码实现：
```
class Solution {
    public String longestPalindrome(String s) {
        String result = "";
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            // 两种情况
            // 第一种：以middleChar为中心，两边对称。
            int x = i-1, y = i + 1;
            for (; x >= 0 && y < chars.length; x--, y++) if (chars[x] != chars[y]) break;
            result = s.substring(x + 1, y).length() > result.length() ? s.substring(x + 1, y) : result;
            // 第二种：middleChar和下一个字符对称。两边对称
            x=i;
            y = i + 1;
            for (; x >= 0 && y < chars.length; x--, y++) if (chars[x] != chars[y]) break;
            result = s.substring(x < i ? x + 1 : x, y).length() > result.length() ? s.substring(x < i ? x + 1 : x, y) : result;
        }
        return result;
    }
}
```
