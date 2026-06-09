### 解题思路
根据字符串生成字符串

### 代码

```java
class Solution {
    public  String countString(String str) {
        StringBuilder sb = new StringBuilder();
        int count = 0, left = 0, right = 0;
        char[] chars = str.toCharArray();
        while (right < str.length()) {
            if (chars[left] == chars[right]) {
                count++;
                right++;
            } else {
                sb.append((char) ('0' + count)).append(chars[left]);
                left = right;
                count = 0;
            }
        }
        sb.append((char) ('0' + count)).append(chars[right - 1]);
        return sb.toString();
    }

    public   String countAndSay(int n) {
        String tmp = "1";
        if (n == 1) return tmp;
        for (int i = 0; i < n - 1; i++) {
            tmp = countString(tmp);
        }
        return tmp;

    }
}
```