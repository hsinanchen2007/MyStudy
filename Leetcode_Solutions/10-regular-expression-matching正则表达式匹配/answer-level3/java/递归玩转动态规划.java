思路分析：
- 首先还是建立暴力递归的思想：如果我们要求整体字符串s和p是否可以匹配，可以通过s和p的前缀字符串的匹配信息来推导出当前字符串的匹配情况。
- 这里给一张图展示思路过程吗，绿色小旗子我们可以直接返回的结果，不需要计算，红色小旗子依赖子问题的求解：

![image.png](https://pic.leetcode-cn.com/3549e48ae87d7e46962f06cc505701d0d84bbaa2a3f079bcaf551b3b1359c906-image.png)
- 下面就是将思路用代码实现： 用两个指针cs,cp分别表示当前需要匹配s的前cs个字符串和p的前cp个字符串。
```
    // LeeCode10: 正则表达式匹配
    public boolean isMatch(String s, String p) {
        return getMatchRes(s, s.length(), p, p.length());
    }

    // cs当前选定s字符串取得前cs各字符串，cp指针表示选定当前p字符串的前cp个字符
    private boolean getMatchRes(String s, int cs, String p, int cp) {
        // 边界条件，如果p的指针cp走到头了，s的指针没走到头，肯定匹配不上返回false
        if (cp == 0) return cs == 0;
        if (cp < 0) return false;
        // 如果s为null，
        if (cs == 0) {
            if (p.charAt(cp - 1) == '*') {
                return getMatchRes(s, cs, p, cp - 2);
            } else {
                return false;
            }
        }
        // 分情况讨论：
        // 情况一：如果当前的cs和cp位置的字符相等，或者cp位置的字符是'.',那么直接返回s和p格子前进一位的结果
        if (s.charAt(cs - 1) == p.charAt(cp - 1) || p.charAt(cp - 1) == '.') {
            return getMatchRes(s, cs - 1, p, cp - 1);
        }
        // 情况二，当前s和p位置的字符不相等时，两种可能性，一个时p为'*',还有一个p为字母
        if (p.charAt(cp - 1) == '*') {
            if ((cp < 2 || (s.charAt(cs - 1) != p.charAt(cp - 2)) && p.charAt(cp - 2) != '.')) {
                return getMatchRes(s, cs, p, cp - 2);
            } else {
                return getMatchRes(s, cs - 1, p, cp) || getMatchRes(s, cs, p, cp - 1) || getMatchRes(s, cs, p, cp - 2);
            }
        }
        return false;
    }
```
这把就很爽了，一次AC，不过必须要优化的，暴力递归的重复计算是不能接收的。继续分析递归代码
- 创建一个`boolean[][]`类型的`dp`数组，数组中存放的元素就是暴力递归每个步骤的结果，那么dp的属性很容易就可以定出来，`dp = new boolean[s.length()][p.length(0)]`
- 从递归代码可以看出当前的格子依赖上面的格子，左一位的格子，以及左二位的格子，直接将格子替换到代码里面，如下：

```
class Solution {
    // LeeCode10: 正则表达式匹配
    public boolean isMatch(String s, String p) {
        if(p.equals("")) return s.equals("");
        // 创建dp数组
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        // 遍历数组填数组
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= p.length(); j++) {
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }else if(j == 0){
                    dp[i][j] = false;
                }else if(i == 0){
                    if(p.charAt(j - 1) == '*' && j - 1 > 0){
                        dp[i][j] = dp[i][j - 2];
                    }else{
                        dp[i][j] = false;
                    }
                }else if(s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p.charAt(j - 1) == '*'){
                    if (j > 1 && (s.charAt(i - 1) != p.charAt(j - 2)) && p.charAt(j - 2) != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else if(j == 1){
                        dp[i][j] = false;
                    } else{
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    }
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
}
```
- 顺利AC，继续优化，boolean类型默认值为false，所有有很多没有必要写上去代码，优化结果如下：
```
class Solution {
    // LeeCode10: 正则表达式匹配
    public boolean isMatch(String s, String p) {
        if(p.equals("")) return s.equals("");
        // 创建dp数组
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        // 遍历数组填数组
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= p.length(); j++) {
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }else if(j == 0 || (j == 1 && p.charAt(j - 1) == '*')){
                    dp[i][j] = false;
                }else if(i == 0){
                    if(p.charAt(j - 1) == '*' && j - 1 > 0){
                        dp[i][j] = dp[i][j - 2];
                    }
                }else if(s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p.charAt(j - 1) == '*'){
                    if ((s.charAt(i - 1) != p.charAt(j - 2)) && p.charAt(j - 2) != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else{
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    }
                }
            }
        }
        return dp[s.length()][p.length()];
    }
}
```
- 走到这里，这个问题的执行效率已经非常高了，当然这里空间上还可以继续优化，不过对于列而言，需要依赖左边两个格子的状态，所以感觉有一定难度，这里不花时间去琢磨了，有机会再回头来试试。