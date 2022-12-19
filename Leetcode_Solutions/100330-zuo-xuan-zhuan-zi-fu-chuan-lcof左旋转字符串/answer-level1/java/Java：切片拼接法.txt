### 解题思路
先用String类的substring方法进行字符串切片，
再用StringBuffer的拼接，
主要字符串切片的下标不要写错。
时间复杂度：O(1)
空间复杂度：O(n)，n是字符串的长度

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        return new StringBuffer(s.substring(n, s.length())).append(s.substring(0,n)).toString();
    }
}
```