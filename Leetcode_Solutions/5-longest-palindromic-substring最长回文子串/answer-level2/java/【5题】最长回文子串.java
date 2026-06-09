**方法一：动态规划**
```
class Solution {
    /**
    * 思路：
    * 假设字符串s的长度为length，建立一个length*length的矩阵dp。
    * 令 dp[i][j] 表示 S[i] 至 S[j] 所表示的子串是否是回文子串。
    * (1) 当 i == j，dp[i][j] 是回文子串（单字符都是回文子串）；
    * (2) 当 j - i < 3，只要 S[i] == S[j]，则 dp[i][j] 是回文子串（如"aa"，“aba”），否则不是；
    * (3) 当 j - i >= 3，如果 S[i] == S[j] && dp[i+1][j-1] ，则 dp[i][j] 是回文子串，否则不是。
    */
    public String longestPalindrome(String s) {
        if(s == null || s.length() == 0){
            return "";
        }
        String res = "";
        boolean[][] dp = new boolean[s.length()][s.length()];
        int max = 0;
        // 遍历元素并得到包含当前元素之前字符串的最大回文子串。
        for (int i = 0; i < s.length(); i++){
            for (int j = 0; j <= i; j++){
                dp[j][i] = s.charAt(j) == s.charAt(i) && ((i - j <= 2) || dp[j+1][i-1]);
                if (dp[j][i]){
                    if(i - j + 1 > max){
                        max = i - j + 1;
                        res = s.substring(j,i + 1);
                    }
                }
            }
        }
        return res;
    }
}
```

**方法二：中心扩散法**
```
class Solution {
    /**
    * 思路：
    * 长度为奇数的回文子串中心有一个元素，例如 "aba" 的中心元素为 "b" ；
    * 长度为偶数的回文子串中心有两个元素，例如 "abba" 的中心元素为 "bb" 。
    * 分别以两种中心为基础寻找并比较出最长回文子串。
    */
    public String longestPalindrome(String s) {
        if(s == null || s.length() == 0){
            return "";
        }
        // 记录回文子串开始和结束的位置
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = Math.max(len1,len2);
            // 根据回文子串的长度和i推算出回文子串的起始位置
            if(len > end - start){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(start, end + 1);
    }

    /**
     *  返回以left和right位置为中心的最大回文串长度
     *  当 left == right 时，表示以一个元素为中心。
     */
    private int expandAroundCenter(String s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
            L--;
            R++;
        }
        return R - L - 1;
    }
}
```

**方法三：Manacher(马拉车)算法**
```
class Solution {
    /**
    * 算法思考比较复杂，但是消耗时间少。优化了中心扩展方法。
    * 思路：
    * (1) 将传入字符串通过添加特殊字符都变成奇数串处理，例如："aba" ==> "#a#b#a#"。
    * (2) 遍历字符，用一个数组记录以当前字符为中心的最长回文串的长度半径。
    * (3) 每次遍历，如果当前字符在已知回文串最右边界的左边，
    *       那么就计算其相对最右边界回文串中心对称的位置，得出已知回文串的半径，
    *       判断该半径如果到达了最右边界，则进行中心扩展探索当前字符为中心的最长回文串。
    *       如果当前字符在已知回文串最右边界上或是最右边界的右边，
    *       则直接进行中心扩展探索当前字符为中心的最长回文串。
    * (4) 每次中心扩展完，比较更新最右边界和相对应的回文串中心，同时比较记录最长回文子串的中心和半径。
    * (5) 得到最长回文子串，去掉特殊符号。
    */
    public String longestPalindrome(String s) {
        // 先预处理字符串
        String str = preHandleString(s);
        // 处理后的字串长度
        int len = str.length();
        // 右边界
        int right = 0;
        // 右边界对应的回文串中心
        int rightCenter = 0;
        // 保存以每个字符为中心的回文长度一半（向下取整）
        int[] halfLenArr = new int[len];
        // 记录回文子串中心
        int center = 0;
        // 记录最长回文子串长度
        int longestHalf = 0;
        for(int i = 0; i < len; i++) {
            // 是否需要中心扩展
            boolean needCalc = true;
            // 如果在右边界的覆盖之内
            if(right > i) {
                // 计算i相对rightCenter的对称位置
                int leftCenter = 2 * rightCenter - i;
                // 根据回文性质得到的结论，回文串的对称点回文对称
                halfLenArr[i] = halfLenArr[leftCenter];
                // 如果超过了右边界，进行调整
                if(i + halfLenArr[i] > right) {
                    halfLenArr[i] = right - i;
                }
                // 如果根据已知条件计算得出的最长回文小于右边界，则不需要扩展了
                if(i + halfLenArr[leftCenter] < right) {
                    // 直接推出结论
                    needCalc = false;
                }
            }
            // 中心扩展得出以当前元素为中心的最长回文子串半径
            if(needCalc) {
                while(i - 1 - halfLenArr[i] >= 0 && i + 1 + halfLenArr[i] < len) {
                    if(str.charAt(i - 1 - halfLenArr[i]) == str.charAt(i + 1 + halfLenArr[i])) {
                        halfLenArr[i]++;
                    } else {
                        break;
                    }
                }
                // 更新右边界及相对应的回文串中心
                right = i + halfLenArr[i];
                rightCenter = i;
                // 记录最长回文子串的中心和半径
                if(halfLenArr[i] > longestHalf) {
                    center = i;
                    longestHalf = halfLenArr[i];
                }
            }
        }
        // 去掉之前添加的#
        StringBuilder sb = new StringBuilder();
        for(int i = center - longestHalf + 1; i <= center + longestHalf; i += 2) {
            sb.append(str.charAt(i));
        }
        return sb.toString();
    }

    /**
    * 预处理字符串，在所有字符两边都加上#
    */
    private String preHandleString(String s) {
        StringBuilder sb = new StringBuilder();
        int len = s.length();
        sb.append('#');
        for(int i = 0; i < len; i++) {
            sb.append(s.charAt(i));
            sb.append('#');
        }
        return sb.toString();
    }
}
```
