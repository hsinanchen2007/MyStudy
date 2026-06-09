### 解题思路
dfs

### 代码

```java
class Solution {
	static boolean[][]visited;
    public static int movingCount(int m, int n, int k) {
    	//设置boolean数组标记访问状态
    	visited = new boolean[m][n];
    	//设置递归查找方法
    	return search(0, 0, m, n, k);
    }
    private static int search(int x,int y,int m,int n,int k) {
    	//设置递归终止的base case
		if (x>=m||y>=n||visited[x][y]||(x%10+x/10+y%10+y/10)>k) {
			return 0;
		}
		//其他情况则标记、+1、继续找
		visited[x][y]=true;
		return 1+search(x+1, y, m, n, k)+search(x, y+1, m, n, k);
	}
}
```