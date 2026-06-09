>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度和空间复杂度均是O(nm)。

执行用时：2ms，击败52.80%。消耗内存：37.8MB，击败17.33%。

```java
public class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int[][] nums = new int[n][m];
        for (int i = 0; i < indices.length; i++) {
            for (int j = 0; j < m; j++) {
                nums[indices[i][0]][j]++;
            }
            for (int j = 0; j < n; j++) {
                nums[j][indices[i][1]]++;
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((nums[i][j] & 1) == 1) {
                    result++;
                }
            }
        }
        return result;
    }
}
```

# 解法二：统计每行每列增加的次数

时间复杂度和空间复杂度均是O(n + m)。

执行用时：0ms，击败100.00%。消耗内存：37.6MB，击败19.65%。

```java
public class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int[] rows = new int[n], cols = new int[m];
        for (int i = 0; i < indices.length; i++) {
            rows[indices[i][0]]++;
            cols[indices[i][1]]++;
        }
        int colEven = 0, colOdd = 0, result = 0;
        for (int i = 0; i < m; i++) {
            if ((cols[i] & 1) == 1) {
                colOdd++;
            } else {
                colEven++;
            }
        }
        for (int i = 0; i < n; i++) {
            if ((rows[i] & 1) == 1) {   //第i行加1的次数为奇数次，那么该行中对应加1的次数为偶数次的列上的数是奇数
                result += colEven;
            } else {
                result += colOdd;   //第i行加1的次数为偶数次，那么该行中对应加1的次数为奇数次的列上的数是奇数
            }
        }
        return result;
    }
}
```