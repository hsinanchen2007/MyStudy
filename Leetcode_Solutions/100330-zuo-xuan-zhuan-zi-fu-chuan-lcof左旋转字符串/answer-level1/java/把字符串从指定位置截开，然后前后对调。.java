### 解题思路
从指定位置截开前后对调。

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
           return s.substring(n)+s.substring(0,n);
    }
}
```