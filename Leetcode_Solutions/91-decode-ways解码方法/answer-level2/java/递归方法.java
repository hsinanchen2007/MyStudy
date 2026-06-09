### 解题思路
递归

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        char[] chars = s.toCharArray();
        if (chars[0]=='0') return 0;
        return decode(chars, chars.length - 1);
    }

    private int decode(char[] chars, int index) {
        if (index <= 0) return 1;
        int count = 0;
        int curr = chars[index];
        int prev = chars[index-1];

        if (curr > '0') {
            count += decode(chars, index - 1);
        }

        if (prev == '1' || (prev == '2' && curr <= '6')) {
            count += decode(chars, index - 2);
        }
        return count;
    }
}
```