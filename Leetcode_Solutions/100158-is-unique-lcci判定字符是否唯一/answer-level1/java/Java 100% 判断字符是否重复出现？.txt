### 解题思路
借助空间来实现。

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        if (astr == null || astr.length() <= 1) {
            return true;
        }
        boolean[] array = new boolean[256];
        for (int i = 0; i < astr.length(); i++) {
            if (array[astr.charAt(i)]) {
                return false;
            }
            array[astr.charAt(i)] = true;
        }

        return true;
    }
}
```