### 解题思路
执行用时 :
3 ms
, 在所有 Java 提交中击败了
98.01%
的用户
内存消耗 :
38.4 MB
, 在所有 Java 提交中击败了
11.63%
的用户

### 代码

```java
class Solution {
    public String multiply(String num1, String num2) {
        // 从最后一位逐个加起来
        if (num1.equals("0") || num2.equals("0")) return "0";
        StringBuilder sb = new StringBuilder();
        int len1 = num1.length(), len2 = num2.length();
        int[] ans = new int[len1 + len2];
        for (int i = len2 - 1; i >= 0; i--) {
            int low = num2.charAt(i) - '0';
            for (int j = len1 - 1; j >= 0; j--) {
                ans[len1 + len2 - 2 - i - j] += (num1.charAt(j) - '0') * low;
            }
        }
        int incre = 0;
        for (int i = 0; i < len1 + len2; i++) {
            ans[i] += incre;
            incre = ans[i] / 10;
            sb.append(ans[i] % 10);
        }
        // 若第一位是0 则不需要添加进去
        String s = sb.reverse().toString();
        if (s.startsWith("0")) return s.substring(1);
        return s;
    }
}
```