### 解题思路
我也不知道这么一道简单的题目我为啥写了这么长的代码

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder s = new StringBuilder();
        int add = 0;
        int i = a.length() - 1, j = b.length() - 1;
        while (i > -1 || j > -1) {
            if (i == -1) {
                if (b.charAt(j) == '0' && add == 1 || b.charAt(j) == '1' && add == 0) {
                    add = 0;
                    s.append('1');
                } else if (b.charAt(j) == '1' && add == 1) {
                    add = 1;
                    s.append('0');
                } else if (b.charAt(j) == '0' && add == 0) s.append('0');
                j--;
                continue;
            } else if (j == -1) {
                if (a.charAt(i) == '0' && add == 1 || a.charAt(i) == '1' && add == 0) {
                    add = 0;
                    s.append('1');
                } else if (a.charAt(i) == '1' && add == 1) {
                    add = 1;
                    s.append('0');
                } else if (a.charAt(i) == '0' && add == 0) s.append('0');
                i--;
                continue;
            }
            if (a.charAt(i) == '0' && b.charAt(j) == '0') {
                if (add == 1) {
                    s.append('1');
                    add = 0;
                } else s.append('0');
            } else if (a.charAt(i) == '0' || b.charAt(j) == '0') {
                if (add == 1) s.append('0');
                else s.append('1');
            } else {
                if (add == 1) {
                    s.append('1');
                } else {
                    add = 1;
                    s.append('0');
                }
            }
            i--;
            j--;
        }
        if (add == 1) s.append('1');
        return s.reverse().toString();
    } 
}
```