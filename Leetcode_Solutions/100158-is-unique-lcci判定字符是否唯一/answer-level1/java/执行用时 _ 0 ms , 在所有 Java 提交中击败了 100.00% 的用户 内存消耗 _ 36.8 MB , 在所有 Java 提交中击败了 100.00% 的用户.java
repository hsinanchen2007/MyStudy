### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char temp[] = astr.toCharArray();
        for (char e : temp) {
            if (astr.indexOf(e) != astr.lastIndexOf(e)) {
                return false;
            }
        }
        return true;
    }
}
```