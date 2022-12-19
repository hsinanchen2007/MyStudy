>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度和空间复杂度均是O(N ^ 2)。

执行用时：9ms，击败27.83%。消耗内存：69.9MB，击败5.20%。

```java
public class Solution {
    public int findJudge(int N, int[][] trust) {
        boolean[][] graph = new boolean[N + 1][N + 1];  //graph[i][j]表示第i个人信任第j个人
        for (int[] edge : trust) {
            graph[edge[0]][edge[1]] = true;
        }
        int result = -1;
        for (int i = 1; i <= N; i++) {
            boolean isJudge = true; //判断第i个人是否是小镇的法官
            for (int j = 1; j <= N; j++) {
                if (i != j && graph[i][j]) {
                    isJudge = false;
                    break;
                }
            }
            if (isJudge) {
                for (int j = 1; j <= N; j++) {
                    if (i != j && !graph[j][i]) {
                        isJudge = false;
                        break;
                    }
                }
            }
            if (isJudge) {
                if (result != -1) {
                    return -1;
                }
                result = i;
            }
        }
        return result;
    }
}
```

# 解法二：记录每个节点的入度和出度

法官是入度为N-1，出度为0的节点。

时间复杂度和空间复杂度均是O(N)。

执行用时：4ms，击败48.11%。消耗内存：60.2MB，击败22.58%。

```java
public class Solution {
    public int findJudge(int N, int[][] trust) {
        int[] outDegrees = new int[N + 1], inDegrees = new int[N + 1];
        for (int[] edge : trust) {
            outDegrees[edge[0]]++;
            inDegrees[edge[1]]++;
        }
        int result = -1;
        for (int i = 1; i <= N; i++) {
            if (outDegrees[i] == 0 && inDegrees[i] == N - 1) {
                if (result != -1) {
                    return -1;
                }
                result = i;
            }
        }
        return result;
    }
}
```