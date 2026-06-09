### 解题思路
为什么s.substring(n, s.length())执行用时是0ms，s.substring(n)是1ms？
### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        return s.substring(n, s.length())+s.substring(0,n);
    }
}
```