### 解题思路
从最后一位开始遍历，第一次出现空格就继续往前遍历，一旦出现非空格就开始累计出现非空格的次数，当再次出现空格就退出循环。空格的ASCII码是32。

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0;
        boolean flag = true;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (flag && (c == 32)) {
                continue;
            }
            if (c != 32) {
                flag = false;
                count++;
                continue;
            }
            break;
        }
        return count;
    }
}
```