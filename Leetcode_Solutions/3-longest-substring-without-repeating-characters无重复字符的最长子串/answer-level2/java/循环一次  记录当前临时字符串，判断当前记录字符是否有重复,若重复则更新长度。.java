### 解题思路
循环一次 每次入循环时先判断当前字符是否有重复， 若有重复则获取当前字符串长度， 重置更新最长字符串(截取重复字符后的字符串)并继续拼接当前字符。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        String temp = "";
        int max = 0;
        int length = s.length();
        for(int i = 0; i < length; i++) {
            char c = s.charAt(i);
            int repeatIndex = temp.indexOf(c + "");
            if (repeatIndex != -1) {
                max = Math.max(temp.length(), max);
                temp = temp.substring(repeatIndex + 1, temp.length());
            }

            temp += c;
            if (i == length - 1) {
                max = Math.max(temp.length(), max);
            }


        }
        return max;
    }
}
```