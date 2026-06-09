## 思路:

思路一:动态规划

- 自底向上

  动态方程:

  用`dp[i][j]`表示`s1`的前`i`元素和`s2`前`j`元素是否交错组成`s3`前`i+j`元素

  所以有动态方程:

  `dp[i][j] = (dp[i-1][j] && s3[i+j-1] == s1[i-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1])`

  注意:针对第一行,第一列要单独考虑

- 自顶向下

思路二: BFS



## 代码:

```python [1]
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)
        n3 = len(s3)
        if n1 + n2 != n3: return False

        dp = [[False] * (n2 + 1) for _ in range(n1 + 1)]

        dp[0][0] = True
        # 第一行
        for j in range(1, n2 + 1):
            dp[0][j] = (dp[0][j - 1] and s2[j - 1] == s3[j - 1])

        # 第一列
        for i in range(1, n1 + 1):
            dp[i][0] = (dp[i - 1][0] and s1[i - 1] == s3[i - 1])
        # print(dp)

        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                dp[i][j] = (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) or (
                        dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])
        # print(dp)
        return dp[-1][-1]
```



```java [1]
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if (n1 + n2 != n3) return false;
        boolean[][] dp = new boolean[n1 + 1][n2 + 1];
        dp[0][0] = true;
        // 第一行
        for (int j = 1; j <= n2; j++) dp[0][j] = (dp[0][j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1));
        // 第一列
        for (int i = 1; i <= n1; i++) dp[i][0] = (dp[i - 1][0] && s1.charAt(i - 1) == s3.charAt(i - 1));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
            }
        }
        return dp[n1][n2]; 
    }
}
```

自顶向下

```python [2]
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        import functools
        n1 = len(s1)
        n2 = len(s2)
        n3 = len(s3)
        @functools.lru_cache(None)
        def helper(i, j, k):
            if i == n1 and j == n2 and k == n3:
                return True
            if k < n3:
                if i < n1 and s1[i] == s3[k] and helper(i+1, j, k+1):
                    return True
                if j < n2 and s2[j] == s3[k] and helper(i, j+1, k+1):
                    return True
            return False
        return helper(0,0,0)
```

思路二:

```python [3]
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        from collections import deque
        n1 = len(s1)
        n2 = len(s2)
        n3 = len(s3)
        if n1 + n2 != n3: return False

        queue = deque()
        queue.appendleft((0, 0))
        visited = set()
        while queue:
            i, j = queue.pop()
            if i == n1 and j == n2:
                return True
            if i < n1 and s1[i] == s3[i + j] and (i + 1, j) not in visited:
                visited.add((i + 1, j))
                queue.appendleft((i + 1, j))
            if j < n2 and s2[j] == s3[i + j] and (i, j + 1) not in visited:
                visited.add((i, j + 1))
                queue.appendleft((i, j + 1))
        return False
```



```java [3]
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if (n1 + n2 != n3) return false;
        boolean[][] visited = new boolean[n1 + 1][n2 + 1];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        while (!queue.isEmpty()) {
            int[] tmp = queue.poll();
            if (tmp[0] == n1 && tmp[1] == n2) return true;
            if (tmp[0] < n1 && s1.charAt(tmp[0]) == s3.charAt(tmp[0] + tmp[1]) && !visited[tmp[0] + 1][tmp[1]]) {
                visited[tmp[0] + 1][tmp[1]] = true;
                queue.offer(new int[]{tmp[0] + 1, tmp[1]});
            }
            if (tmp[1] < n2 && s2.charAt(tmp[1]) == s3.charAt(tmp[0] + tmp[1]) && !visited[tmp[0]][tmp[1] + 1]) {
                visited[tmp[0]][tmp[1] + 1] = true;
                queue.offer(new int[]{tmp[0], tmp[1] + 1});
            }

        }
        return false;
    }
}
```

