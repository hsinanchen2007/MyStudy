### 解题思路
注意点：
1. 字符串只由a,b组成
2. 回文子序列而不是子串，子序列可以不是连续的(不知道有没有说对)

思路：
如果是回文串，则一次即可删除，如果不是回文串，那么把所有a或者所有b删除后，剩下的一定是回文的，即再删除一次即可。
所以，答案区间[0-2]。

### 代码

```java
class Solution {
    public int removePalindromeSub(String s) {
        
        if (s.length() == 0) return 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) return 2;  // 不是回文串
        }

        return 1;
    }
}
```

执行用时 :1 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :34.3 MB, 在所有 Java 提交中击败了100.00%的用户