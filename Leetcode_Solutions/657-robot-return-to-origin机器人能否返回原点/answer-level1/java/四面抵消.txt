### 解题思路
1. 比较向上和向下的个数是否相等 以及向左和向右的个数是否相等

### 代码

```java
class Solution {
    public boolean judgeCircle(String moves) {
        int leftRight = 0;
        int upDown = 0;
        for (char c : moves.toCharArray()) {
            if (c == 'R') {
                leftRight++;
            } else if (c == 'L') {
                leftRight--;
            } else if (c == 'U') {
                upDown++;
            } else {
                upDown--;
            }
        }
        return leftRight == 0 && upDown == 0;
    }
}
```