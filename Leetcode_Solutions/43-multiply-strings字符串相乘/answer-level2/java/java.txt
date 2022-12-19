### 解题思路
此处撰写解题思路  dd 

### 代码

```java
class Solution {
    public String multiply(String num1, String num2) {
        int m = num1.length();
        int n = num2.length();

//        String[] result = new String[m + n + 1];
        char[] result = new char[m + n];

        // 循环遍历两个字符串，将 num1[i] 与 num2[j] 相乘，并可以将结果存入到 value[i + j + 1] 中
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 字符 相乘 注意
                result[i + j + 1] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
            }
        }

        // 处理进位
        for (int i = m + n - 1; i > 0; i--) {
            if (result[i] >= 10) {
                result[i - 1] += result[i] / 10;
                result[i] %= 10;
            }
        }

        // 处理前端的 0
        int beginIndex = 0;
        while (beginIndex < result.length - 1 && result[beginIndex] == 0) {
            beginIndex++;
        }

        // 转化为数字 字符
        for (int i = beginIndex; i < result.length; i++) {
            result[i] += '0';
        }
        return new String(result, beginIndex, result.length - beginIndex);
    }
}
```