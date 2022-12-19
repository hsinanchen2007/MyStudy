### 解题思路
此处撰写解题思路
1.审题：将所有的空格替换成%20；
2.方法:没方法：直接用String中的replace()方法；将字符串中指定字符替换成另外一个字符；
### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        String str = s.replace(" ","%20");
        return str;
    }
}
```