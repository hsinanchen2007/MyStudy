### 解题思路
substring、concat产生新的对象

### 代码

```java
class Solution {
    public static String reverseLeftWords(String s, int n) {
        String newstr = s.substring(0,n);
        s = s.substring(n,s.length());
        return s.concat(newstr);
    }
}
```