
```java []
public class P10 {

    public static void main(String[] args) {
        Solution0 solution = new Solution0();
        System.out.println(solution.isMatch("ab", ".*c"));
        System.out.println(solution.isMatch("aa", "a*"));
        System.out.println(solution.isMatch("adwbbci", ".*bci"));
        System.out.println(solution.isMatch("aaa", "ab*a"));
        System.out.println(solution.isMatch("aaa", "ab*a*c*a"));
    }

    /**
     * 基础版，83ms
     */
    static class Solution {
        public boolean isMatch(String s, String p) {
            if (s.equals(p)) {
                return true;
            }
            // 如果s != p但是p为空，说明s不为空，说明不匹配
            if (p.isEmpty()) {
                return false;
            }
            // 否则如果s为空，则firstMatch为false，s和p第一个字符不匹配或者p第一个字符不为.都为false
            boolean firstMatch = !s.isEmpty() && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.');
            if (p.length() > 1 && p.charAt(1) == '*') {
                /**
                 * isMatch(s, p.substring(2))表示*前面跟s匹配数为0的情况（或减少到跟*后面完全匹配），例如abcd 和 c*abcd
                 * (firstMatch && isMatch(s.substring(1), p)表示*前面跟s匹配不为0的情况
                 * 但是不为0不知道匹配多少个，所以匹配到就将s减去一个进行递归
                 * 例如 aaaaaabcd 和 a*aabcd，会一直走(firstMatch && isMatch(s.substring(1), p)
                 * 直到aaaaaabcd减少到aabcd，发现isMatch(s, p.substring(2))为true，则返回true
                 */
                return isMatch(s, p.substring(2)) || (firstMatch && isMatch(s.substring(1), p));
            } else {
                /**
                 * 这里表示p为一个字符例如a或者p为多个字符但是第二个不为*比如ab···
                 * 然后如果第一个字符匹配即firstMatch为true，则比较两个字符串剩下的
                 */
                return firstMatch && isMatch(s.substring(1), p.substring(1));
            }
        }
    }

    /**
     * 字符串截取改成下标表示，34ms，超过40%+
     */
    static class Solution0 {
        public boolean isMatch(String s, String p) {
            if (s.equals(p)) {
                return true;
            }
            return isMatch(s, p, 0, 0, s.length(), p.length());
        }

        private boolean isMatch(String s, String p, int si, int pi, int sl, int pl) {
            if (si >= sl && pi >= pl) {
                return true;
            }
            if (pi >= pl) {
                return false;
            }
            boolean firstMatch = si < sl && (s.charAt(si) == p.charAt(pi) || p.charAt(pi) == '.');
            if (pl - pi > 1 && p.charAt(pi + 1) == '*') {
                return isMatch(s, p, si, pi + 2, sl, pl) || (firstMatch && isMatch(s, p, si + 1, pi, sl, pl));
            } else {
                return firstMatch && isMatch(s, p, si + 1, pi + 1, sl, pl);
            }
        }
    }

    /**
     * 在下标的基础上增加dp，超过99.88%
     */
    static class Solution1 {

        private int[][] dp;

        public boolean isMatch(String s, String p) {
            if (s.equals(p)) {
                return true;
            }
            dp = new int[s.length() + 1][p.length() + 1];
            return isMatch(s, p, 0, 0, s.length(), p.length());
        }

        private boolean isMatch(String s, String p, int si, int pi, int sl, int pl) {
            if (dp[si][pi] != 0) {
                return dp[si][pi] > 0;
            }
            if (si >= sl && pi >= pl) {
                return true;
            }
            if (pi >= pl) {
                return false;
            }
            boolean firstMatch = si < sl && (s.charAt(si) == p.charAt(pi) || p.charAt(pi) == '.');
            boolean res;
            if (pl - pi > 1 && p.charAt(pi + 1) == '*') {
                res = isMatch(s, p, si, pi + 2, sl, pl) || (firstMatch && isMatch(s, p, si + 1, pi, sl, pl));
            } else {
                res = firstMatch && isMatch(s, p, si + 1, pi + 1, sl, pl);
            }
            dp[si][pi] = res ? 1 : -1;
            return res;
        }
    }
}
```


