### 解题思路
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * 先遍历一遍 有多少空格n，申请长度后 len+2*n
 * 然后从后面开始复制，如果遇到空格，则将%20复制进去

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        int n = 0;
        for (int i=0;i<s.length();i++) {
            if (s.charAt(i) == ' ') {
                n++;
            }
        }
        char[] chars = new char[s.length()+2*n];
        int i = chars.length-1,j=s.length()-1;
        while (i>=0 && j>=0) {
            if (s.charAt(j) == ' ') {
                chars[i--] = '0';
                chars[i--] = '2';
                chars[i--] = '%';
                j--;
            } else {
                chars[i--] = s.charAt(j--);
            }
        }
        return new String(chars);
    }
}
```
![image.png](https://pic.leetcode-cn.com/70bd59a6c0f051f04650738c178131c40f704125e05e4a46de5f5f2bc216fc08-image.png)
