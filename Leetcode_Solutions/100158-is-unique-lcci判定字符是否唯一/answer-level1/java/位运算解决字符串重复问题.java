### 解题思路
位运算

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int mark = 0;
        for (char c : astr.toCharArray()) {
            int markBit = c - 'a';
            if ((mark & (1 << markBit)) != 0) {
                return false;
            } else {
                mark |= (1 << markBit);
            }
        }
        return true;
    }
}
```