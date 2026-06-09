### 解题思路
不敢说题解，只是个人代码思路的整理集。

### 代码

```java
class Solution {
    public boolean isMatch(String text, String pattern) {
        // text 为被匹配的字符串
        // pattern 为正则表达式 .为任意字符, *为连续任意数目(0~n)个的前面一位字符, .*为任意字符连续任意个(只能匹配单个字符的连续任意个)
        //返回值为 正则表达式与字符串是否能匹配上。
        if (pattern.isEmpty()) return text.isEmpty();
        return activeList(text, pattern);
    }

    public boolean backwards(String text, String pattern){
        //回溯法: 遇到*时直接跳过当前字符的连续字符

        //当正则表达式时空时, 只需要判断字符串是否为空即可计算出结果
        if (pattern.isEmpty()) return text.isEmpty();
        //算法的主要内容, 匹配单个字符
        boolean first_match = (!text.isEmpty() &&
                               (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));
        //遇到正则表达式长度大于2, 且第二位为*号时, 开始匹配连续字符.
        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
            // 返回结果: 该字符为连续0个? || 该字符为连续n个? (通过剔除第0位字符位, 一直进入到连续字符结束遇到新字符的位置, 重新进入返回值的前一个判断中, 并拦截掉*,进入下一段的匹配。)
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
            //非*号情况，进入下一位的判断。
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }

    public boolean activeList(String text, String pattern){
        // 动态规划, 基于回溯算法的优化版，将结果保存起来，当遇到false时, 或者正则匹配不完整直接返回，不再浪费时间过多运算.
        boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
        dp[text.length()][pattern.length()] = true;

        for (int i = text.length(); i >= 0; i--){
            for (int j = pattern.length() - 1; j >= 0; j--){
                boolean first_match = (i < text.length() &&
                                       (pattern.charAt(j) == text.charAt(i) ||
                                        pattern.charAt(j) == '.'));
                if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
}

```