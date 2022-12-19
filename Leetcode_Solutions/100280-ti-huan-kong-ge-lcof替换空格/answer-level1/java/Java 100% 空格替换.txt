### 解题思路
统计空格出现的次数，然后从后一次遍历构建最终结果char数组即可。

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        if (s == null || s.length() == 0) {
            return s;
        }
        int length = s.length();
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == ' ') {
                count++;
            }
        }

        if (count == 0) {
            return s;
        }
        char[] result = new char[length + 2 * count];
        int index = length + 2 * count - 1;
        for (int i = length - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ') {
                result[index--] = '0';
                result[index--] = '2';
                result[index--] = '%';
            } else {
                result[index--] = s.charAt(i);
            }
        }

        return String.valueOf(result);
    }
}
```