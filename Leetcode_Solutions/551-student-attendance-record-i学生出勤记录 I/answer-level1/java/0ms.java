### 解题思路
一遍遍历
1.countA用于标记A的个数，超过1返回false
2.countL用于标记L的个数，如果当前是L，向下探一位，看是否还是L，注意这里要防止数组越界，这个探一位也是字符串操作中常用的。

### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
        int countA = 0;
        for (int i = 0; i < s.length(); i++) {
            int countL = 1;
            if (s.charAt(i) == 'A') {
                countA++;
                if (countA > 1) {
                    return false;
                }
            }
            if (s.charAt(i) == 'L') {
                while (i+1 < s.length() && s.charAt(i + 1) == 'L') {
                    countL++;
                    i++;
                }
                if (countL > 2) {
                    return false;
                }
            }
        }
        return true;
    }
}
```