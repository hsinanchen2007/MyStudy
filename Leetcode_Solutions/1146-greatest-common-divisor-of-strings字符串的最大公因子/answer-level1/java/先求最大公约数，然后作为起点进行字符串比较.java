### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * @Author : josan
 * @Date : 2020/3/12 21:32
 * @Package : leetcode.study.biggroup011.group053.ex1071
 * @ProjectName: pom-parent
 * @Description:
 */
public class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (str1 == null || str1.isEmpty()) {
            return "";
        }
        if (str2 == null || str2.isEmpty()) {
            return "";
        }

        int len1 = str1.length();
        int len2 = str2.length();
        if (len1 < len2) {
            String tmp = str1;
            str1 = str2;
            str2 = tmp;
        }

        return gcdOfStringsInner(str1, str2);
    }

    private String gcdOfStringsInner(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        int len = gcd(len1, len2);
        while (len >= 1) {
            if (len2 % len == 0 && len1 % len == 0) {
                if (isSubString(str2, len2, str2, len)
                        && isSubString(str1, len1, str2, len)) {
                    return str2.substring(0, len);
                }
            }
            --len;
        }

        return "";
    }

    private int gcd(int a, int b) {
        int c = a % b;
        while (c != 0) {
            a = b;
            b = c;
            c = a % b;
        }
        return b;
    }

    private boolean isSubString(String str1, int ed1,
                                String str2, int ed2) {
        /***
         * str1 == str2 是指针位置相比
         */
        if (str1 == str2 && ed1 == ed2) {
            return true;
        }

        int i = 0;
        while (i < ed1) {
            if (str1.charAt(i) == str2.charAt(i % ed2)) {
                ++i;
            } else {
                return false;
            }
        }
        return true;
    }
}

```

```
package leetcode.study.biggroup011.group053.ex1071;

import org.junit.Assert;
import org.junit.Test;

/**
 * @Author : josan
 * @Date : 2020/3/12 21:32
 * @Package : leetcode.study.biggroup011.group053.ex1071
 * @ProjectName: pom-parent
 * @Description:
 */
public class TestSolution {
    @Test
    public void testGcdOfStrings() {
        doTestGcdOfStrings("ABCABC", "ABC", "ABC");
        doTestGcdOfStrings("ABABAB", "ABAB", "AB");
        doTestGcdOfStrings("LEET", "CODE", "");
        doTestGcdOfStrings("NLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGM", "NLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGMNLZGM", "NLZGM");
    }

    private void doTestGcdOfStrings(String str1, String str2, String expected) {
        Solution solution = new Solution();
        Assert.assertEquals("not the same", expected,
                solution.gcdOfStrings(str1, str2));
    }
}
```