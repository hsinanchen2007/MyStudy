### 解题思路
如果s2是由s1旋转而来，那将s1 += s1 之后，s2必定为其子串

### 代码

```java
class Solution {
    public boolean isFlipedString(String s1, String s2) {
        if(s1 == null || s2 == null || s1.length() != s2.length()) {
            return false;
        }
        s1 += s1;
        if(!s1.contains(s2)) {
            return false;
        }
        return true;
    }
}
```