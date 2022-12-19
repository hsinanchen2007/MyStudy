### 执行结果：通过
执行用时 : 2 ms , 在所有 Java 提交中击败了 99.39% 的用户
内存消耗 : 39.3 MB , 在所有 Java 提交中击败了 100.00% 的用户
### 解题思路
- 1.先把两个字符串长度差额绝对值大于等于2的过滤了。
- 2.while 循环两个字符串，对位如果不想等。那就长的字符串移位，短的不动，相等的一起动。并且记一次错误次数。让短的当前位置继续与长的下一位比较。继续前面移位规则和记录规则。
- 3.如果两个位置的字符相等就一起移位。
- 4.错误次数达到就跳出循环。判断初始的状态 =true 且 错误小于2 。

### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        int fi = (first == null ? 0 : first.length() - 1);
        int si = (second == null ? 0 : second.length() - 1);
        boolean br = Math.abs(fi - si) < 2;
        int ei = 0;
        while ((fi >= 0 || si >= 0) && ei < 2 & br) {
            if (fi >= 0 && si >= 0 && first.charAt(fi) == second.charAt(si)) {
                fi--;
                si--;
            } else {
                if (fi == si) {
                    fi--;
                    si--;
                } else {
                    if (fi > si)
                        fi--;
                    else
                        si--;
                }
                ei++;
            }

        }
        br = br && ((ei < 2));
        return br;
    }
}
```