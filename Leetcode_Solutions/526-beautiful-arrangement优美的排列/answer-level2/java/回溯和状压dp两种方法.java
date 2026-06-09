### 解题思路
此处撰写解题思路

### 代码

从n往下走
```java
class Solution {
    int res = 0;

    public int countArrangement(int N) {
        int[] arr = new int[N];
        Arrays.fill(arr, -1);
        dfs(arr, N);
        return res;
    }

    //数组以及放置数字的个数
    private void dfs(int[] arr, int n) {
        if (n == 0) {
            res++;
            return;
        }
        //枚举每个位置，如果这个位置没有被放置过，且符合要求，就可以尝试放置
        //我这里直接从n开始，当然你可以设置从1开始枚举每个pos到N
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == -1 && (n % (i + 1) == 0 || (i + 1) % n == 0)) {
                arr[i] = i;
                dfs(arr, n - 1);
                arr[i] = -1;
            }
        }
    }
}
```

从pos为1一直到n
```java
class Solution {
    int res = 0;

    public int countArrangement(int N) {
        int[] arr = new int[N];
        Arrays.fill(arr, -1);
        // dfs(arr, N);
        dfs(arr, 1, N);
        return res;
    }

    //数组以及放置数字的个数
    private void dfs(int[] arr, int pos, int n) {
        if (pos > n) {
            res++;
            return;
        }
        //枚举每个位置，如果这个位置没有被放置过，且符合要求，就可以尝试放置
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == -1 && (pos % (i + 1) == 0 || (i + 1) % pos == 0)) {
                arr[i] = i;
                dfs(arr, pos + 1, n);
                arr[i] = -1;
            }
        }
    }
}
```

状压dp
我们的最终目的是得到状态为【1111...111】n个1的情况下，它有多少种排列，那其实就可以从1枚举到n，对于每个位上的数字，只有0（代表没放）和1（代表放了）这两种状态。假设现在枚举到了状态 x，看一下它这个状态是否满足题目中的条件，如果满足，那就可以加进去。
```java
class Solution {
    public int countArrangement(int N) {
        int[] dp = new int[1 << N];
        for (int i = 0; i < N; i++) {
            dp[1 << i] = 1;
        }
        for (int i = 1; i < 1 << N; i++) {
            if (dp[i] > 0) {
                int pos = 0;
                for (int j = 0; j < N; j++) {
                    if ((i & (1 << j)) != 0) {
                        pos++;
                    }
                }
                for (int j = 0; j < N; j++) {
                    if (((i & (1 << j)) == 0) && ((pos + 1) % (j + 1) == 0 || (j + 1) % (pos + 1) == 0)) {
                        dp[i | 1 << j] += dp[i];
                    }
                }
            }
        }
        return dp[(1 << N) - 1];
    }
}
```