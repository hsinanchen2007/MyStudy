### 解题思路
1. 将26个字母放到一个数组里
2. 遍历字符串值，如果遇到#，则根据#前两位算出对应字母，否则根据当前位算出对应字母
3. 注意：这里 char 转 int 效率高的方法是 '1' - '0' = 1 ,如果 (int)'1' = 49 是错误的结果
![image.png](https://pic.leetcode-cn.com/610d353e970ed1748113827a8f02b6aeb2cb48522b10aed47c938ae3a291f992-image.png)

### 代码

```java
class Solution {
    public String freqAlphabets(String s) {
        char[] alphabetChars = new char[27];
        for (int i = 1; i < alphabetChars.length; i++) {
            alphabetChars[i] = (char) (96 + i);
        }
        StringBuilder builder = new StringBuilder();
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (i < chars.length - 2 && chars[i + 2] == '#') {
                builder.append(alphabetChars[(chars[i] - '0') * 10 + (chars[i + 1] - '0')]);
                i += 2;
            } else {
                builder.append(alphabetChars[chars[i] - '0']);
            }
        }
        return builder.toString();
    }
}
```