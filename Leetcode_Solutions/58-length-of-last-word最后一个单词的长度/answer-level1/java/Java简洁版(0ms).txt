简洁易懂
```java
class Solution {
    public int lengthOfLastWord(String s) {
        int i = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s.charAt(j) != ' ') {
                i++;
                continue;
            }
            if (i > 0) return i;
        } 
        return i;
    }
}
```
