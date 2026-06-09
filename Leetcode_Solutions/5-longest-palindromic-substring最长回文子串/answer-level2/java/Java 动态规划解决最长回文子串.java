### 解题思路
简单的递归思路是 
判断s[i:j]是否是回文
```
palindrome(i,j)=s[i]==s[j]&&palindrome(i+1,j-1); (j>i+1)
```
简单的递归，肯定是会超时的。

**优化方案：由递归转成迭代**
以`s="abada"`为例
间隔d=0 p(0,0)=true p(1,1)=true .....p(4,4)=true
d=1 p(0,1)=s[0]==s[1] p(1,2)=s[1]==s[2] .....p(3,4)=s[3]==s[4]
d=2 p(0,2)=s[0]==s[2]&&p(1,1)  p(1,3)=s[1]==s[3]&&p(2,2)...... p(2,4)=s[2]==s[4]&&p(3,3)
d=3 p(0,3)=s[0]==s[3]&&p(1,2) .....p(1,4)=s[1]==s[4]&&p(2,3)
d=4 p(0,4)=s[0]==s[4]&&p(1,3)

首先计算出第一行的结果，依次计算出后面行的结果

### 代码

```java
class Solution {
        public String longestPalindrome(String s) {
        if (s.equals(""))
            return s;
        char[] str = s.toCharArray();
        int len = s.length();
        boolean[][] p = new boolean[len][len];
        int left = 0, right = 0, maxLen = 1;

        for (int j = 0; j < len; j++) {//间隔d
            for (int i = 0; i < len; i++) {
                if (i + j >= len)
                    continue;
                if (j == 0)
                    p[i][i] = true;
                else if (j == 1)
                    p[i][i + j] = str[i] == str[i + j];
                else p[i][i + j] = str[i] == str[i + j] && p[i + 1][i + j - 1];
                int currentLen = j + 1;
                if (p[i][i + j] == true && maxLen < currentLen) {
                    left = i;
                    right = i + j;
                    maxLen = currentLen;
                }
            }
        }

        return s.substring(left, right + 1);
    }
}
```