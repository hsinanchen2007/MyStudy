### 解题思路
substring()
### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        String str = s.substring(n);
        str += s.substring(0,n) ;
        return str;

    }
}
```