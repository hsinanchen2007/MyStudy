### 解题思路
两个字符串中的字符相加求和后相减，将结果转换为char类型即解决问题

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        int sumS = 0;
        for (char ch : s.toCharArray()) {
            sumS += ch;
        }
        int sumT = 0;
        for (char ch : t.toCharArray()) {
            sumT += ch;
        }
        return (char) (sumT - sumS);
    }
}
```