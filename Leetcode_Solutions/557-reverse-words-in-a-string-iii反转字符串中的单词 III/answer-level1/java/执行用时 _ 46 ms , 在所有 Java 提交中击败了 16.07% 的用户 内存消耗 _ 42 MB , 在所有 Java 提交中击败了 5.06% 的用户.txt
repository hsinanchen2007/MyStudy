### 解题思路
本题属于简单题，考察对于字符串切分和翻转的相关知识，首先我们以空格为标志进行切分，得到一个字符串数组，对每一个字符串进行翻转，这里利用StringBuilder中的reverse方法比较简便，最后把所有翻转完成的字符串进行相加，但是我们需要把收尾空格去掉，使用trim方法即可，然后返回字符串。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] arr = s.split(" +");
        String ss = "";
        for(String str:arr) {
            ss+=new StringBuilder(str).reverse().toString();
            ss=ss+" ";
        }
        
        return ss.trim();
    }
}
```