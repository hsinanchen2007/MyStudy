# 一、暴力解法
   暴力法是最容易想到的，同时也是时间复杂度最高的。首先是判断一个字符串是否为回文，就是从其中间往边界扩展判定。见isPalindromic方法。之后将给定字符串取所有字串，判断是否为回文。时间复杂度为O(n^3)代码如下：
    public String longestPalindromeBaoLi(String s) {
        int len = s.length();
        String ans = "";
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len + 1; j++) {
                String temp = s.substring(i,j);
                if((j - i) > ans.length() && isPalindromic(temp)){
                    if (ans.length() < temp.length()){
                        ans = temp;
                    }

                }
            }
        }
        return ans;
    }

    public boolean isPalindromic(String s){
        char[] chars = s.toCharArray();
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if(chars[i] != chars[len-1-i]){
                return false;
            }
            if(i == (len/2)+1){
                break;
            }
        }
        return true;
    }
# 二、动态规划
  利用布尔类型的二位数组可以用空间换取时间，将时间复杂度降为O(n^2)。二位数组的横纵坐标i和j代表子串的边界。存入的值为其是否为回文字符串。过程分为三个阶段：
1、找出i、j相等和字符串连续的情况（如：aaa），赋值为true。
2、基于之前的结果，从值为true的位置扩展，如果所扩的i和j的char值也相等，则为回文，继续判断。
3、遍历二位数组找出值为true的j-i+1最大值，最后返回字符串结果。
代码如下：
    public String longestPalindromeDynamic(String s) {D
        if(s.equals("")){
            return s;
        }
        boolean dp[][] = new boolean[s.length()][s.length()];

        //判单独和连续
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (j == (i + 1)) {
                    dp[i][j] = (s.charAt(i) == s.charAt(j));
                }
            }
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.length(); j++) {
                if (j == (i + 1)) {
                    continue;
                }
                //i右往左，j左往右，所以里面内层是i+1,j-1
               dp[i][j] = (dp[i + 1][j - 1] && s.charAt(i) == s.charAt(j));
            }
        }

        int maxLength = 0, maxI = 0, maxJ = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (dp[i][j] && (j - i + 1) > maxLength) {
                    maxLength = j - i + 1;
                    maxI = i;
                    maxJ = j;
                }
            }
        }
        return s.substring(maxI, maxJ + 1);
    }
参考：https://blog.csdn.net/qq_32651225/article/details/80165662
