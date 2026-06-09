```

/**
 * 回溯解法
 *
 * @author jianghe
 * @since 2020-03-29
 */
class Solution {
    public boolean isMatch(String s, String p) {
        // 记录上一次通配符匹配到哪
        int lastPattern = -1;
        // 记录上一次通配符的位置
        int lastPatternPos = -1;
        // target的左坐标
        int left1 = 0;
        // pattern的左坐标
        int left2 = 0;

        while (left1 < s.length()) {
            // 相同的字符直接进位即可
            if (left2 < p.length()
                && (s.charAt(left1) == p.charAt(left2) || p.charAt(left2) == '?')) {
                left1++;
                left2++;
            } else if (left2 < p.length() && p.charAt(left2) == '*') {
                // 此时leftPattern位置的字符和leftTarget位置的字符不同
                lastPattern = left1;
                lastPatternPos = left2;
                left2 = lastPatternPos + 1;
            } else if (lastPattern != -1) {
                // leftPattern位置的字符不是*
                // 多匹配一位
                lastPattern++;
                left1 = lastPattern;
                left2 = lastPatternPos + 1;
            } else {
                return false;
            }
        }
        return isAllPattern(left2, p);
    }

    private boolean isAllPattern(int leftPattern, String p) {
        for (int i = leftPattern; i < p.length(); i++) {
            if (p.charAt(i) != '*') {
                return false;
            }
        }
        return true;
    }
}


/**
 * 动态规划
 *
 * @author jianghe
 * @since 2020-03-29
 */
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] record = new boolean[s.length() + 1][p.length() + 1];

        record[0][0] = true;
        // p为空时，s不为空的话record一定是false
        // s为空，p不为空的话需要p全部是*号
        for (int i = 1; i <= p.length(); i++) {
            record[0][i] = isAllPattern(p.substring(0, i));
        }
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (p.charAt(j - 1) == s.charAt(i - 1) || p.charAt(j - 1) == '?') {
                    record[i][j] = record[i - 1][j - 1];
                    continue;
                }
                if (p.charAt(j - 1) == '*') {
                    // 分别对应着*匹配多个、*匹配0个
                    record[i][j] = record[i - 1][j] || record[i][j - 1];
                }
            }
        }
        return record[s.length()][p.length()];
    }

    private boolean isAllPattern(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '*') {
                return false;
            }
        }
        return true;
    }
}
```
