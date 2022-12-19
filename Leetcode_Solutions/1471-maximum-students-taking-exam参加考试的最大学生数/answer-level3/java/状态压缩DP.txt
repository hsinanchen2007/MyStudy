### 解题思路
参考了大佬们的写法，花了一个下午总算写对了，可见熟练程度还不够，移位运算符，进制转化还要多练

### 代码

```java
class Solution {

    char[][] nums;
    public int maxStudents(char[][] seats) {
        nums = seats;
        int row = seats.length;
        int col = seats[0].length;
        int[][] dp = new int[row][1 << col];
        for (int j = 0; j < (1 << col); j++) {
            if (ok1(row - 1, j)) dp[row - 1][j] = Integer.bitCount(j);
        }
        for (int i = row - 2; i >= 0; i--) {
            for (int k = 0; k < (1 << col); k++) {
                for (int j = 0; j < (1 << col); j++) {
                    if (ok1(i + 1, k) && ok1(i, j) && ok(k, j)) {
                        dp[i][j] = Math.max(dp[i][j], dp[i + 1][k] + Integer.bitCount(j));
                    }
                }
            }
        } 
        int res = 0; 
        for (int j = 0; j < (1 << col); j++) res = Math.max(res, dp[0][j]);
        return res;
    }
    boolean ok(int k, int j) {
        if ((j << 1 & k) != 0 || (j >> 1 & k) != 0) return false;
        return true;
    }
    boolean ok1(int i, int k) {
        if ((k << 1 & k) != 0 || (k >> 1 & k) != 0) return false;
        char[] c = new char[nums[0].length];
        int a = c.length - 1;
        while (a >= 0) {
            c[a] = k == 0 ? '0' : k % 2 == 1 ? '1' : '0';
            k /= 2;
            a--;
        }
        for (int j = 0; j < nums[0].length; j++) {
            if (nums[i][j] == '#' && c[j] == '1') return false;
        }
        return true;
    }
}
```