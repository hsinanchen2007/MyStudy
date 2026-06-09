欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n1 * n2)，其中n1为字符串haystack的长度，n2为字符串needle的长度。
空间复杂度是O(1)。

执行用时；4ms，击败40.43%。消耗内存：37.2MB，击败61.27%。

```java
public class Solution {
    public int strStr(String haystack, String needle) {
        int n1 = haystack.length(), n2 = needle.length();
        if (n2 == 0) {
            return 0;
        }
        for (int i = 0; i < n1 - n2 + 1; i++) {
            if (haystack.charAt(i) == needle.charAt(0)) {
                boolean flag = true;
                for (int j = 1; j < n2; j++) {
                    if (haystack.charAt(i + j) != needle.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
}
```

# 解法二：KMP算法

时间复杂度是O(n1 + n2)，其中n1为字符串haystack的长度，n2为字符串needle的长度。
空间复杂度是O(n2)。

执行用时；11ms，击败12.12%。消耗内存：36.8MB，击败76.60%。

```java
public class Solution {
    public int strStr(String haystack, String needle) {
        int n2;
        if (null == needle || (n2 = needle.length()) == 0) {
            return 0;
        }
        int n1;
        if (null == haystack || (n1 = haystack.length()) == 0) {
            return -1;
        }
        int[] next = getNext(needle);
        int j = -1;
        for (int i = 0; i < n1; i++) {
            while (j != -1 && haystack.charAt(i) != needle.charAt(j + 1)) {
                j = next[j];
            }
            if (haystack.charAt(i) == needle.charAt(j + 1)) {
                j++;
            }
            if (j == n2 - 1) {
                return i - j;
            }
        }
        return -1;
    }

    private int[] getNext(String p) {
        int n = p.length();
        int[] next = new int[n];
        int j = -1;
        next[0] = -1;
        for (int i = 1; i < n; i++) {
            while (j != -1 && p.charAt(i) != p.charAt(j + 1)) {
                j = next[j];
            }
            if (p.charAt(i) == p.charAt(j + 1)) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }
}
```