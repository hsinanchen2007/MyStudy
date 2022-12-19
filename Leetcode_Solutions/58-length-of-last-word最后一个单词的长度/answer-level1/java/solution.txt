### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
if (null == s || s.isEmpty()) {
            return 0;
        }
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (count == 0 && s.charAt(i) == ' ') {
                continue;
            } else if (count != 0 && s.charAt(i) == ' ') {
                break;
            } else {
                count++;
            }
        }
        return count;
    }
}
```