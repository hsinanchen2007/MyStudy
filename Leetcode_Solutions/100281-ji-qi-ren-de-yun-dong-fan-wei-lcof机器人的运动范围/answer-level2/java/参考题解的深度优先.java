### 解题思路
深度优先
类似于递归的反向思维

### 代码

```java
class Solution {
	int m, n, k;
    public int movingCount(int m, int n, int k) {
    	this.m = m;
    	this.n = n;
    	this.k = k;
    	boolean[][] visited = new boolean[m][n];
    	return dfs(0, 0, visited);
    }
    //深度优先
    public int dfs(int x, int y, boolean[][] visited) {
    	if (x >= m || y >= n || get(x) + get(y) > k || visited[x][y]) {
			return 0;
		}
    	visited[x][y] = true;
    	return 1 + dfs(x+1, y, visited) + dfs(x, y+1, visited);
    }
    public int get(int x) {
    	int sum = 0;
    	while (x > 0) {
			sum += x%10;
			x /= 10;
		}
    	return sum;
    }
}
```