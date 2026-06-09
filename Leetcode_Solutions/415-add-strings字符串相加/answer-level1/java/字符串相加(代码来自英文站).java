> 原解法地址 [Straightforward Java 8 main lines 25ms](https://leetcode.com/problems/add-strings/discuss/90436/Straightforward-Java-8-main-lines-25ms)

## 方法一：模拟进位

**算法**

每次处理最后两个字符数字，进行模拟进位

```java
public class Solution {

    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int carry = 0; // 进位
        for(int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || carry == 1; i--, j--){
            int x = i < 0 ? 0 : num1.charAt(i) - '0';
            int y = j < 0 ? 0 : num2.charAt(j) - '0';
            sb.append((x + y + carry) % 10);
            carry = (x + y + carry) / 10;
        }
        return sb.reverse().toString();
    }
}
```

