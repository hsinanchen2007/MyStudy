### 解题思路
双指针

### 代码

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        if (name.charAt(0)!=typed.charAt(0)) return false;
        int i=1;
        for (int j=1; i<name.length() && j<typed.length(); j++) {
            if (name.charAt(i)==typed.charAt(j)) {
                i++;
            } else if (typed.charAt(j)!=typed.charAt(j-1)) {
                return false;
            }
        }
        return i==name.length();
    }
}
```