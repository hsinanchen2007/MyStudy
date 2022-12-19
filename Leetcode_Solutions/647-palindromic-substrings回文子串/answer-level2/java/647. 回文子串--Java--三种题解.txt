[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_647_countSubstrings.java)

```java
 /**
     * 解法一：
     * 定义两个指针，从0到len判断所有的回文可能性，性能不一定高，结果一定对（时间复杂度O(n^3)）
     * 执行用时 :116 ms, 在所有 Java 提交中击败了12.26%的用户
     * 内存消耗 :34.3 MB, 在所有 Java 提交中击败了92.34%的用户
     * <p>
     * 解法二：{@link _647_countSubstrings#countSubstrings2(String)}
     *
     * 解法三：{@link _647_countSubstrings#countSubstrings3(String)}
     *
     * @param s
     * @return
     */
    public int countSubstrings(String s) {
        int retCount = 0;
        int start, end;
        for (start = 0; start < s.length(); start++) {
            for (end = start; end < s.length(); end++) {
                if (isPalindrome(s, start, end)) {
                    retCount++;
                }
            }
        }

        return retCount;
    }

    private boolean isPalindrome(String s, int start, int end) {
        while (start <= end) {
            if (s.charAt(start) != s.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    /**
     * 解法二：中心扩展==>时间复杂度O(n^2)
     * 从中心（区分1个点的中心还是两个点的中心）向两边同时扩散，如左右两边都相等则是回文，继续扩散
     *
     * 执行用时 :2 ms , 在所有 Java 提交中击败了99.02%的用户
     * 内存消耗 :34 MB, 在所有 Java 提交中击败了92.79%的用户
     *
     * @param s
     * @return
     */
    public int countSubstrings2(String s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            //分奇偶考虑
            res += countSegment(s, i, i);
            res += countSegment(s, i, i + 1);
        }
        return res;
    }

    //start往左边跑，end往右边跑, 判断s[start, end]是否为回文
    public int countSegment(String s, int start, int end) {
        int count = 0;
        while (start >= 0 && end < s.length() && s.charAt(start--) == s.charAt(end++))
            count++;
        return count;
    }

    /**
     * 解法三：动态规划==>时间复杂度O(n^2)
     * 基本原理同解法二，只是用动态规划的方式求解出来了
     *
     * 执行用时 :11 ms, 在所有 Java 提交中击败了47.66%的用户
     * 内存消耗 :35.6 MB, 在所有 Java 提交中击败了86.94%的用户
     * @param s
     * @return
     */
    public static int countSubstrings3(String s) {
        int result = 0;
        boolean[][] dp = new boolean[s.length()][s.length()];

        for (int i = s.length()-1; i >=0 ; i--) {
            for (int j = i; j < s.length(); j++) {
                if (i==j)
                    dp[i][j] = true;
                else
                    dp[i][j] = s.charAt(i)==s.charAt(j) && (j<=i+1 || dp[i+1][j-1]);
                if (dp[i][j]) result++;
            }
        }

        return result;
    }

```