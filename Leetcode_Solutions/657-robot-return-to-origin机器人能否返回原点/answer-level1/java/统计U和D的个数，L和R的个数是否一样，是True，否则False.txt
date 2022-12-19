### 解题思路

```java
class Solution {
    public boolean judgeCircle(String moves) {
        int du =0;
        int lr=0;
        char[] chars = moves.toCharArray();
        for (char ch : chars) {
            if (ch == 'U') du++;
            else if (ch == 'D') du--;
            else if (ch == 'R') lr++;
            else if (ch == 'L') lr--;
        }
        return du ==0 && lr ==0;
    }
}
```