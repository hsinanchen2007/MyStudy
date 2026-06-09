### 解题思路
根据官方思路：先找到单独一个字符对应的回文子串，两个字符对应的回文子串，
然后根据一个字符和两个字符左右各加一个来找到所有的回文子串；
子问题：字符串下标从i到j的最大回文子串；
状态方程：
(1)奇数个字符串：result[i][i] = 1 or 0
(2)偶数个字符串：result[i][i+1] = 1 pr 0
状态转移方程：
result[i-1][j+1] = result[i][j] + if (Si == Sj)
转移方程只有一种，即左右各加一个判断是否合理

### 代码

```java
class Solution {
    int [][] result;
    String s;
    int maxLength;
    int maxLeft;
    int maxRight;
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return s;
        }
        this.s = s;
        result = new int[s.length()][s.length()];
        for (int i=0;i<s.length();i++) {
            result[i][i] = 1;
            find(i, i, 1);
            if (i != s.length()-1) {
                if (s.charAt(i) == s.charAt(i+1)) {
                    if (maxLength < 1) {
                        maxLength = 1;
                        maxLeft = i;
                        maxRight = i + 1;
                    }
                    result[i][i+1] = 1;
                    find(i, i+1, 1);
                }
            } 
        }
        return s.substring(maxLeft, maxRight+1);
    }
    public void find(int i, int j, int type) {
        if (type == 0) {
            return;
        }
        if (i < 1 || j > s.length()-2) {
            return;
        }
        if (s.charAt(i-1) == s.charAt(j+1)) {
            result[i-1][j+1] = 1;
            if (maxLength < (j - i + 2)) {
                maxLength = j - i + 2;
                maxLeft = i - 1;
                maxRight = j + 1;
            }
            find(i-1, j+1, 1);

        }
    }
}
```