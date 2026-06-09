### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
       String s = S + "$";
        char[] chars = s.toCharArray();
        StringBuilder builder = new StringBuilder();
        int i = 0;
        int j = 0;
        for (; j < chars.length; j++) {
            if (chars[i] != chars[j]) {
                builder.append(chars[i]).append(j - i);
                i = j;
            }
        }
        //与原字符串大小进行对比
        return builder.length() >= S.length() ? S : builder.toString();
    }
}
```

使用char[]转成数组后处理，降低内存消耗，使用charAt多了越界溢出等判断，消耗内存，时间复杂度o(n)