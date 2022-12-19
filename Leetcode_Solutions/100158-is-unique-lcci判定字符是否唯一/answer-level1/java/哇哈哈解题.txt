### 解题思路
最简单的就是遍历对比。还可以用set去重的思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char[] chars = astr.toCharArray();
        int length = chars.length;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (chars[i] == chars[j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```