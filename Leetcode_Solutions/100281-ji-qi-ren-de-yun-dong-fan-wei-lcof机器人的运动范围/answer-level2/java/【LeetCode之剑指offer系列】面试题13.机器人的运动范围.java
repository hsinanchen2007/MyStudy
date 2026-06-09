### 题目讲解
先来用画图的方式给大家讲解一下题目的意思
1. 假如地上有一个 `m = 2` 行 `n = 3` 列的方格，从坐标 `[0,0]` 到坐标 `[m-1, n-1]`
![image.png](https://pic.leetcode-cn.com/703b8dc2bc3e241cd968ef461740e1955b4bf8806cc6cc269ec3c535c4c8506d-image.png)
2. 机器人从坐标 `[0, 0]` 的格子开始移动，每次可以向左、右、上、下移动一格，但是不能移动到方格外，也不能进入行坐标和列坐标的数位之和大于 `k = 1` 的格子，所以机器人能到达的格子即为下图的**蓝色格子**
![image.png](https://pic.leetcode-cn.com/f2fffebbf758727e5e82b3a182bb6c2450f9b08e93bc474a8406338539c89d94-image.png)

### 解题思路
1. 定义 `sum` 来统计能够到达的格子数，定义 `boolean` 类型的二维数组 `active` 来存放机器人是否到达过该格子
2. 定义一个计算方法 `cul`，用来计算当前格子坐标的数位之和
3. 进入递归方法 `solve`，把起始坐标点 `x = 0`，`y = 0`，方格的行数 `m`，列数 `n`，最大数位和 `k` 传递进去
4. 设置退出递归的条件：x、y 超出，该格子已经遍历过，行列坐标的数位之和大于 k，即 `x >= rows || y >= cols || active[x][y] || cul(x, y) > k`
5. 如果以上条件不满足的话，则设置该格子已经遍历过并且因为满足条件 `sum` 加1，即 `active[x][y] = true; sum++;`，并且**继续往下方和右边的格子进行递归**

### 代码
```java
class Solution {
    private int sum;
    public int movingCount(int m, int n, int k) {
        sum = 0;
        boolean[][] active = new boolean[m][n];
        solve(0, 0, m, n, k, active);
        return sum;
    }

    // 计算当前格子坐标的数位之和
    private int cul(int x, int y) {
        int res = 0;
        while(x != 0) {
            res += x % 10;
            x = x / 10;
        }
        while(y != 0) {
            res += y % 10;
            y = y / 10;
        }
        return res;
    }

    private void solve(int x, int y, int rows, int cols, int k, boolean[][] active) {
        if(x >= rows || y >= cols || active[x][y] || cul(x, y) > k) {
            return;
        }

        active[x][y] = true;
        sum++;

        // 继续往下方和右边的格子进行递归
        solve(x, y + 1, rows, cols, k, active);
        solve(x + 1, y, rows, cols, k, active);
    }
}
```