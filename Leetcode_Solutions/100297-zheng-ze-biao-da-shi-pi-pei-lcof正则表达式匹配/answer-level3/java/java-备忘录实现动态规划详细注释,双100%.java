### 解题思路
此处撰写解题思路

### 代码

```java
//备忘录实现动态规划
class Solution {
    //存储子结构是否可被匹配
    //默认是null,而boolean数组默认false
    private Boolean[][] dp;

    public boolean isMatch(String s, String p) {
        dp = new Boolean[s.length()][p.length()];
        //当前字符索引
        int sL = 0;
        int pL = 0;
        return match(s, p, 0, 0);
    }

    private boolean match(String s, String p, int sL, int pL) {
        //递归基(其他情况经过处理最终会变为这种情况)
        if (pL == p.length()) {
            return sL == s.length();
        }
        //备忘录中查找
        if (sL < s.length() && pL < p.length() && dp[sL][pL] != null) {
            return dp[sL][pL];
        }

        boolean flag = false;
        //当前字符的下个字符若为*,有两种情况,匹配0次或匹配n次
        //而n可以用1代表,若有更多次,则会在下轮递归中处理
        if (pL <= p.length() - 2 && p.charAt(pL + 1) == '*') {
            //匹配0次,忽略*和当前字符,p后移2
            flag = match(s, p, sL, pL + 2)
                    //匹配1次,s后移1,p不动,以便1次以上的匹配(前提:s不为空)
                    || (sL <= s.length() - 1 && ((s.charAt(sL) == p.charAt(pL)) || p.charAt(pL) == '.'))
                    && match(s, p, sL + 1, pL);
        } else {
            //下个字符不为*,匹配1次,双双后移1
            flag = (sL <= s.length() - 1 && ((s.charAt(sL) == p.charAt(pL)) || p.charAt(pL) == '.'))
                    && match(s, p, sL + 1, pL + 1);
        }
        //填写备忘录
        if (sL < s.length() && pL < p.length()) {
            dp[sL][pL] = flag;
        }
        return flag;
    }
}

```