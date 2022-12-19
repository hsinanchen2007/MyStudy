### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
               int length = s.length();
        if (length <= 2 || length <= numRows || numRows == 1) {
            return s;
        }
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            int j = 0;
            boolean flag = true;
            while (flag) {
                int num = i + 2 * (numRows - 1) * j;
                if (num < length) {
                    result.append(s.charAt(num));
                } else {
                    flag = false;
                }
                if (i != 0 && i != numRows - 1) {
                    int num2 = i + 2 * (numRows - 1) * j + 2 * (numRows - 1 - i);
                    if (num2 < length) {
                        result.append(s.charAt(num2));
                    } else {
                        flag = false;
                    }
                }
                j++;
            }
        }
        return String.valueOf(result); 
    }
}
```