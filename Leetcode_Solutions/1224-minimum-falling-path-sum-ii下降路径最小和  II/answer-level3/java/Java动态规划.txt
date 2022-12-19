设置二维动态规划数组dp，dp[i][j]表示下降到达**第i行第j列**的最小代价。
设置变量**min**和**second**，分别记录dp数组**代价最小的列下标**、**代价第二小的列下标**。
则状态转移方程：
```
dp[i][j] = dp[i - 1][min] + arr[i][j]
```
或者当 j == min 时
```
dp[i][j] = dp[i - 1][second] + arr[i][j]
```

其中，(i-1, min)表示第i-1行代价最小的位置，(i-1, second)表示第i-1行代价第二小的位置。

由上述描述发现，每次只用到dp数组相邻的两行，可以将dp数组压缩到两行，轮流让这两行充当原本的第i行和第i-1行。
```
class Solution{
    public int minFallingPathSum(int[][] arr) {
        int row = arr.length, column = arr[0].length;
        int[][] dp = new int[2][column];
        int cur = 1, pre = 0;   //cur和pre控制两行轮流充当第i行和第i-1行
        int minIndex = 0, secondIndex = 0;
        for (int i = 0; i < row; i++) {
            int nextMinIndex = 0;
            for (int j = 0; j < column; j++) {
                if(j != minIndex)
                    dp[cur][j] = dp[pre][minIndex] + arr[i][j];
                else dp[cur][j] = dp[pre][secondIndex] + arr[i][j];
                nextMinIndex = dp[cur][nextMinIndex] > dp[cur][j] ? j: nextMinIndex;
            }
            minIndex = nextMinIndex;
            secondIndex = findSecondIndex(dp, cur, minIndex);
            int temp = cur;
            cur = pre;
            pre = temp;
        }
        return dp[pre][minIndex];
    }
    private int findSecondIndex(int[][] dp, int cur, int minIndex){ //找第二小的元素的下标
        int secondIndex = -1;
        for (int j = 0; j < dp[0].length; j++) {
            if(j == minIndex)
                continue;
            if(secondIndex == -1)
                secondIndex = j;
            else secondIndex = dp[cur][secondIndex] > dp[cur][j] ? j: secondIndex;
        }
        return secondIndex;
    }
}
```
