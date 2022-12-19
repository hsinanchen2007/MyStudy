#### 方法一：深度优先搜索 【超时】

**算法**

定义递归方法 $dfs$ 返回第 $weekno$ 周在 $cur\_city$ 城市时，所能最大化的休假天数。

每次方法调用，遍历所有的城市（用 $i$ 来表示）找到跟当前城市相连的城市。这时候有两个选择，留在当前城市或者飞到相连的城市，用 $j$ 来表示下周所在的城市。随后，周数加 1 并进行下一次递归，根据递归结果计算休假天数。休假天数根据下面公式来计算： $days[j][weekno] + dfs(flights, days, j, weekno + 1)$。最后，将休假天数与全局最大休假天数相比较，将全局最大休假天数更新为两者中的最大值。

```java [solution1-Java]
public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        return dfs(flights, days, 0, 0);
    }
    public int dfs(int[][] flights, int[][] days, int cur_city, int weekno) {
        if (weekno == days[0].length)
            return 0;
        int maxvac = 0;
        for (int i = 0; i < flights.length; i++) {
            if (flights[cur_city][i] == 1 || i == cur_city) {
                int vac = days[i][weekno] + dfs(flights, days, i, weekno + 1);
                maxvac = Math.max(maxvac, vac);
            }
        }
        return maxvac;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^k)$。递归树的深度为 $k$，每个节点在最坏情况下会有 $n$ 个分支。其中 $n$ 为城市的数目，$k$ 为周数。

* 空间复杂度：$O(k)$。递归树的深度为 $k$。

#### 方法二：记忆化深度优化搜索【通过】

**算法**

上一个方法中，`dfs` 在输入参数相同的情况下会被多次重复调用，因此可以用记忆化的方式来优化掉这一部分的时间消耗。

为了避免多次重复调用 `dfs`，定义二维数组 $memo$ 来存储 `dfs` 的结果。该数组中，$memo[i][j]$ 用来存储 `dfs(flights, days, i, j)` 的结果。在调用 `dfs` 时，如果 $memo$ 数组已经保存了上次调用的结果，就直接从数组中获取结果。

```java [solution2-Java]
public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        int[][] memo = new int[flights.length][days[0].length];
        for (int[] l: memo)
            Arrays.fill(l, Integer.MIN_VALUE);
        return dfs(flights, days, 0, 0, memo);
    }
    public int dfs(int[][] flights, int[][] days, int cur_city, int weekno, int[][] memo) {
        if (weekno == days[0].length)
            return 0;
        if (memo[cur_city][weekno] != Integer.MIN_VALUE)
            return memo[cur_city][weekno];
        int maxvac = 0;
        for (int i = 0; i < flights.length; i++) {
            if (flights[cur_city][i] == 1 || i == cur_city) {
                int vac = days[i][weekno] + dfs(flights, days, i, weekno + 1, memo);
                maxvac = Math.max(maxvac, vac);
            }
        }
        memo[cur_city][weekno] = maxvac;
        return maxvac;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^2k)$。$memo$ 数组大小为 $n*k$，每次填充需要 $O(n)$ 时间。其中 $n$ 为城市的数量，$k$ 为总周数。

* 空间复杂度：$O(n*k)$。 $memo$ 数组占用空间。

#### 方法三：二维动态规划 【通过】

**算法**

首先阐述一下这个方法背后的思想，第 $j$ 周在第 $i$ 个城市时，最大休假天数跟之前几周在哪渡过已经完全无关了，只跟之后几周怎么渡过有关。因此，可以用动态规划的方法来解决。定义二维数组 $dp$，其中 $dp[i][k]$ 表示第 $k$ 周在第 $i$ 个城市时的最大休假天数。

在填充 $dp[i][k]$ 的时候，有以下几种情况需要考虑：

1. 第 $k$ 周在第 $i$ 个城市时，在第 $k+1$ 周可以选择停留在当前城市。这时候 $dp[i][k]$ 通过 $days[i][k] + dp[i, k+1]$ 计算。

2. 第 $k$ 周在第 $i$ 个城市时，在第 $k+1$ 周可以选择飞到第 $j$ 个城市（$flights[i][j] = 1$）。这时候 $dp[j][k]$ 通过 $days[j][k] + dp[j, k+1]$ 计算。

通过以上分析可知，`dp` 数组是根据周数从后往前填充，最后填充完的 $dp[0][0]$ 就是最大休假天数。

填充 $dp$ 数组的过程详见下面的动画。

<![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/568_Maximum_Vacation_DaysSlide11.PNG)>

```java [solution3-Java]
public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        if (days.length == 0 || flights.length == 0) return 0;
        int[][] dp = new int[days.length][days[0].length + 1];
        for (int week = days[0].length - 1; week >= 0; week--) {
            for (int cur_city = 0; cur_city < days.length; cur_city++) {
                dp[cur_city][week] = days[cur_city][week] + dp[cur_city][week + 1];
                for (int dest_city = 0; dest_city < days.length; dest_city++) {
                    if (flights[cur_city][dest_city] == 1) {
                        dp[cur_city][week] = Math.max(days[dest_city][week] + dp[dest_city][week + 1], dp[cur_city][week]);
                    }
                }
            }
        }
        return dp[0][0];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^2k)$。填满大小为 $n*k$ 的 $dp$ 数组的时间，每次填充消耗时间为 $O(n)$。其中 $n$ 为城市的数量，$k$ 为总周数。

* 空间复杂度：$O(n*k)$。$dp$ 数组的空间消耗。

#### 方法四：一维动态规划 【通过】

**算法**

前一个方法已经提到了，计算第 $i$ 周的 $dp$ 值只需要依赖第 $i+1$ 周的 $dp$ 值。因此，可以直接将周数这个维度省略，将二维数组降为一维数组。

定义 $dp[j]$ 来存储当前周在第 $j$ 个城市的最大休假天数，其余的跟前一个方法几乎一样。为了避免计算出来的下一周数据污染到当前周数据，利用一个 $temp$ 数组来存储运算结果，完整计算之后再重新赋值为 $dp$。

```java [solution4-Java]
public class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        if (days.length == 0 || flights.length == 0) return 0;
        int[] dp = new int[days.length];
        for (int week = days[0].length - 1; week >= 0; week--) {
            int[] temp = new int[days.length];
            for (int cur_city = 0; cur_city < days.length; cur_city++) {
                temp[cur_city] = days[cur_city][week] + dp[cur_city];
                for (int dest_city = 0; dest_city < days.length; dest_city++) {
                    if (flights[cur_city][dest_city] == 1) {
                        temp[cur_city] = Math.max(days[dest_city][week] + dp[dest_city], temp[cur_city]);
                    }
                }
            }
            dp = temp;
        }

        return dp[0];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^2k)$。$dp$ 数组大小为 $n*k$，每次填充消耗时间为 $O(n)$。其中 $n$ 为城市的数量，$k$ 为总周数。

* 空间复杂度：$O(k)$。$dp$ 数组占用空间。