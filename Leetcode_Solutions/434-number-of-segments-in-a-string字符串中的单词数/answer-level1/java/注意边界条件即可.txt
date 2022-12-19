### 解题思路
注意边界条件

### 代码

```java
class Solution {
    public int countSegments(String s) {
        if (s.isEmpty()) {
            return 0;
        }
        String[] strings = s.split(" ");
        int count = 0;
        for (String string : strings) {
            if (string.isEmpty()) {
                continue;
            }
            count++;
        }
        return count;
    }
}
```