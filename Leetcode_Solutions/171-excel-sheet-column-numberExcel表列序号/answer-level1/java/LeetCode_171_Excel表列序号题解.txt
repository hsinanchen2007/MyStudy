### 解题思路

168题目的逆过程

### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        double sum = 0;

        int length = s.length();

        for (int i = length - 1; i >= 0; i--) {
            sum = sum + (s.charAt(i) - 'A' + 1) * Math.pow(26, length - 1 - i);
        }

        return (int) sum;
    }
}
```