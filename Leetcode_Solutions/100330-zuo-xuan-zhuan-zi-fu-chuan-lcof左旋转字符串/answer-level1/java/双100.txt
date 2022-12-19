### 解题思路
没啥可解释的。。。一步步分开写的。。。

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        String str1=s.substring(0,n);
        String str2=s.substring(n);
        StringBuilder sb=new StringBuilder();
        sb.append(str2).append(str1);
        return sb.toString();
    }
}
```