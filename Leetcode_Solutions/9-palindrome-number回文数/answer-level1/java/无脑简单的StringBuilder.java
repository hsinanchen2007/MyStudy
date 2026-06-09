### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        StringBuilder s = new StringBuilder(String.valueOf(x));
        StringBuilder ss = new StringBuilder(s);
        
        return s.toString().equals(ss.reverse().toString());
    }
}
```