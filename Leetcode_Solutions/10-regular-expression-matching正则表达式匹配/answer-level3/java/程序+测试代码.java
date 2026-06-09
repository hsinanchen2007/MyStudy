```

/**
 * @Author : josan
 * @Date : 2020/2/3 9:54
 * @Package : leetcode.study.ex0004
 * @ProjectName: pom-parent
 * @Description:
 */
class Solution {
    public boolean isMatch(String s, String p) {
        if (s == null || p == null) {
            return false;
        }

        return isMatch(s, 0, p, 0);
    }

    private boolean isMatch(String s, int st1, String p, int st2) {
        if (!(st1 < s.length())) {
            char nextCh = 0;
            if (st2 + 1 < p.length()) {
                nextCh = p.charAt(st2 + 1);
            }
            if (nextCh == '*') {
                return isMatch(s, st1, p, st2 + 2);
            } else {
                return !(st2 < p.length());
            }
        }
        if (!(st2 < p.length())) {
            return !(st1 < s.length());
        }

        char ch = p.charAt(st2);
        boolean mutliMatch = false;
        char nextCh = 0;
        if (st2 + 1 < p.length()) {
            nextCh = p.charAt(st2 + 1);
        }
        if (nextCh == '*') {
            mutliMatch = true;
        }

        if (mutliMatch) {
            if (st1 < s.length() &&
                    (s.charAt(st1) == ch || ch == '.')) {
                return isMatch(s, st1, p, st2 + 2) || isMatch(s, st1 + 1, p, st2);
            } else {
                return isMatch(s, st1, p, st2 + 2);
            }
        } else {
            if (st1 < s.length()
                    && (s.charAt(st1) == ch || ch == '.')) {
                return isMatch(s, st1 + 1, p, st2 + 1);
            } else {
                return false;
            }
        }
    }
}
```


```
package leetcode.study.ex0010;

import org.junit.Assert;
import org.junit.Test;

/**
 * @Author : josan
 * @Date : 2020/2/2 21:07
 * @Package : leetcode.study.ex0001
 * @ProjectName: pom-parent
 * @Description:
 */
public class TestSolution {
    @Test
    public void testIsMatch() {
        doTestIsMatch("aa", "a", false);
        doTestIsMatch("aa", "a*", true);
        doTestIsMatch("ab", ".*", true);
        doTestIsMatch("aab", "c*a*b*", true);
        doTestIsMatch("mississippi", "mis*is*p*.", false);
    }

    private void doTestIsMatch(String s, String p, boolean expected) {
        Solution solution = new Solution();
        boolean result = solution.isMatch(s, p);

        Assert.assertEquals("not the same", expected, result);
    }
}

```
