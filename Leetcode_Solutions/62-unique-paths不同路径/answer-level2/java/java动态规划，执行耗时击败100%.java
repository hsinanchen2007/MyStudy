动态规范方程： dp(m,n)=dp(m-1,n)+dp(m,n-1)。
边界点是当m=1或者n=1时，路径值均为1
采用递归的方式进行计算，对于重复的值使用一个数组进行记录。更多leetcode题解[见这里](https://github.com/JessenPan/leetcode)

```
public class S62UniquePaths {

    private Integer[][] array;

    public int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        this.array = new Integer[n][m];
        return findPath(n, m);
    }

    private int findPath(int row, int col) {
        if (row == 1 || col == 1) {
            return 1;
        }

        if (this.array[row - 1][col - 1] != null) {
            return this.array[row - 1][col - 1];
        }

        int val = findPath(row - 1, col) + findPath(row, col - 1);
        this.array[row - 1][col - 1] = val;
        return val;
    }

}
```
