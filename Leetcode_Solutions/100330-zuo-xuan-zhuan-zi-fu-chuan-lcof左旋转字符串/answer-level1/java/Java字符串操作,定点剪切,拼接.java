### 解题思路
此处撰写解题思路
1.观察字符串被反转的位置和给的N值之间的关系
2.运用JAVA中的substring对字符串进行剪切
3.将剪切好的字符串反转拼接(1-2顺序改为2-1顺序)
4.返回目标字符串
### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        int len = s.length();
        String str1 = s.substring(0,n);
        String str2 = s.substring(n,len);
        s= str2.concat(str1);
        return s;
    }
}
```