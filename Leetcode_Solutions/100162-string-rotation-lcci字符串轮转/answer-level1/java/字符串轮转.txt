### 解题思路

### 代码

```java
class Solution {
    public boolean isFlipedString(String s1, String s2) {
        if(s1.length()!=s2.length())
            return false;
        String s=s1+s1;
        if(s.contains(s2))
            return true;
        else
            return false;
    }
}
```