## 预处理
在我们详细探讨解法之前，我们先进行一些准备工作, 这些预处理能帮助增加代码的可读性，并且得到的也是后续许多解法通用的变量。
```
public Solution {

	int m;
	int n;

	// these two arrays help us iterate over four directions
	int[] dr = new int[]{1, -1, 0, 0};
	int[] dc = new int[]{0, 0, 1, -1};
    
    public int maximumMinimumPath(int[][] A) {
        m = A.length;
        if (m != 0) n = A[0].length;
        
        return METHODS_WE_USE_TO_SOLVE_THE_PROBLEM(A);
    }
}
```

***
## 深度优先搜索 (超时错误)
首先，第一眼看到这个题目就很容易想到将每一条可能的路径遍历一遍，再比较他们的值，得到我们的最终解。
```
	int max;
    private int recursivelyDFS(int[][] A) {
        max = Integer.MIN_VALUE;
        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;
        recursivelyDFS(A, 0, 0, A[0][0], visited);
        return max;
    }

    private void recursivelyDFS(int[][] A, int r, int c, int score, boolean[][] visited) {
        if (r == m - 1 && c == n - 1) {
            max = Math.max(max, score);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                visited[nr][nc] = true;
                int ns = A[nr][nc];
                recursivelyDFS(A, nr, nc, Math.min(score, A[nr][nc]), visited);
                visited[nr][nc] = false;
            }
        }
    }
```
时间复杂度: O(V * (V + E)) 其中 V 是可能路径数的最大值（实际上一定会小于顶点数），(V + E)是遍历任意一条可能路径的时间复杂度。
空间复杂度: O(V) V 是搜索树的最大深度。
***
## 用堆优化的深度优先搜索
得到了第一个简单低效的解法后，我们来看一下如何去优化。首先注意到我们的题目是关注路径中的最小值，要求最小值最大，也就是说，我们要让我们的路径尽量避免数值较小的顶点。因此，我们可以把所有和已经访问的节点相邻的点储存起来，然后找到其中最大的点，从这个最大的点往下继续搜索。为了实现这个算法，我们可以用堆来储存这些邻接点，这样堆顶的点就是我们要找的下一个点。
```
	private int orderedDFS(int[][] A) {
        
        PriorityQueue<int[]> heap = new PriorityQueue<>((b, a) -> A[a[0]][a[1]] - A[b[0]][b[1]]);
        boolean[][] visited = new boolean[m][n];
        heap.offer(new int[] {0, 0, A[0][0]});
        
        while (!heap.isEmpty()) {
            int[] curr = heap.poll();
            visited[curr[0]][curr[1]] = true;
            for (int i = 0; i < 4; i++) {
                int nr = curr[0] + dr[i];
                int nc = curr[1] + dc[i];
                if (nr == m - 1 && nc == n - 1) {
                    return Math.min(curr[2], A[nr][nc]);
                }
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int ns = A[nr][nc];
                    heap.offer(new int[]{nr, nc, Math.min(curr[2], ns)});
                }
            }
        }
        return 0;
    }
```
时间复杂度: O(log(V) * (V + E)) 其中 (V + E) 是深度优先搜索找寻一条路径的复杂度而 log(V) 是最坏情况下压入堆的复杂度。
空间复杂度: O(V) 其中 V 是搜索树的最大深度。

***
## 二分搜索法
事实上还有一个更快的算法。我们着重思考一下每个点的取值范围，这个范围在题目中给出了是[0, 10 ^ 9]，也就是说我们可能的候选值有十亿个。我们发现如果一个值是最优解，那么所有小于这个值的数，都会在这个图中找到一条最小值不小于这个数的路径（至少有一条，这条是最优解），因此，我们可以用二分搜索法来找这个值。需要注意的是，二分搜索法找到最优解需要 log_2(10 ^ 9) 约等于 30 次操作，而这个时间复杂度很显然可以看作是常数。
```
 private int binarySearch(int[][] A) {
        int min = 0;
        int max = Math.min(A[0][0], A[m - 1][n - 1]);
        int ans = 0;
        while (max - min > 1) {
            int mid = (min + max) / 2;
            boolean[][] visited = new boolean[m][n];
            visited[0][0] = true;
            if (hasPath(A, 0, 0, visited, mid)) {
                min = mid;
                ans = mid;
            } else {
                max = mid;
            }
        }
        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;
        if (hasPath(A, 0, 0, visited, max)) ans = max;
        return ans;
    }

    private boolean hasPath(int[][] A, int r, int c, boolean[][] visited, int limit) {
        visited[r][c] = true;
        if (r == m - 1 && c == n - 1) return true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && A[nr][nc] >= limit) {
                if (hasPath(A, nr, nc, visited, limit)) return true;
            }
        }
        return false;
    }
```
时间复杂度: O(V + E) 其中 (V + E) 是验证每一条路径需要的时间复杂度。
空间复杂度: O(V) 其中 V 是搜索树的最大深度。
***

如果有朋友发现我的解法有遗漏，分析有错误，或是有疑问，请直接在这条题解下面评论我，我会尽快回复！
（翻译 + 搬运自本人国际版Leetcode的解题思路回答）