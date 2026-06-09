### 解题思路
遍历字符串，如果L字母记数与R字母记数相等，则平衡字符串数量加一

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        // L字母记数
        int cntL = 0;
        // R字母记数
        int cntR = 0;
        // 平衡字符串记数
        int sum = 0;
        char[] chars = s.toCharArray();
        // 遍历字符串，如果L字母记数与R字母记数相等，则平衡字符串数量加一
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == 'L') {
                cntL ++;
            } else {
                cntR ++;
            }
            if (cntL == cntR) {
                sum ++;
            }
        }
        return sum;
    }
}
```