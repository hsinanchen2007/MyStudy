> 执行用时: 0 ms, 在所有 Java 提交中击败了 100.00% 的用户
> 内存消耗: 37.2 MB, 在所有 Java 提交中击败了 100.00% 的用户

### 解题思路
常规位图法，ASCII码一共只有128个。

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        boolean[] map = new boolean[128];
        for(char ch: astr.toCharArray()) {
            if(map[ch - ' ']) {
                return false;
            }
            map[ch - ' '] = true;
        }
        return true;
    }
}
```