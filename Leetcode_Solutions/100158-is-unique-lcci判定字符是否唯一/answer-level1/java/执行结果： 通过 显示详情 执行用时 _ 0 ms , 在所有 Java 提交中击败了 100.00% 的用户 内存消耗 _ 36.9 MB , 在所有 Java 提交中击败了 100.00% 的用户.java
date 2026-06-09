### 解题思路
双指针遍历，一次推进，默认为true，存在相同的元素就将flag置为false。

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
    boolean flag = true;
        char[] chars = astr.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            for (int j = i + 1; j < chars.length; j++) {
                if (chars[i] == chars[j]) flag = false;
            }
        }
        return flag;
    }
}
```