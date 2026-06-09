### 解题思路
此处撰写解题思路、
![image.png](https://pic.leetcode-cn.com/887251371a2078c1cc7f62dd9c822c7055aadf64af5afba57428d3d13ddf25f7-image.png)


### 代码

```java
class Solution {
    public String compressString(String S) {
        StringBuffer buffer = new StringBuffer();
        int count = 0;
        char c = 0;
        int length = 0;
        while (length < S.length()) {
            char c1 = S.charAt(length);
            if (c == c1) {
                count++;
            } else {
                if (count != 0) {
                    buffer.append(c).append(count);
                }
                c = c1;
                count = 1;
            }
            length++;
        }
        if (count != 0) {
            buffer.append(c).append(count);
        }
        return buffer.toString().length()>=S.length()?S:buffer.toString();
    }
}
```