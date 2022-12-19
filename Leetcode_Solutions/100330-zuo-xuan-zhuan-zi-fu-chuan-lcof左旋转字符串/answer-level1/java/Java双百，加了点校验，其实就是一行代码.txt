### 解题思路
此处撰写解题思路
**不需要使用StringBuilder了**，针对这个，编译器会自动进行优化，可以使用IDEA查看编译后的解析：

```java
    public static String reverseLeftWords(String s, int n) {
        if (s != null && s.length() != 0 && n <= s.length()) {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append(s.substring(n)).append(s.substring(0, n));
            return stringBuilder.toString();
        } else {
            return null;
        }
    }
```

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        if(s == null || s.length() == 0 || n > s.length()){
            return null;
        }
        return s.substring(n) + s.substring(0, n);
    }
}
```