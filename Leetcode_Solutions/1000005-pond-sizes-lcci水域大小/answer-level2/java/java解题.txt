DFS：
```
class Solution {
    public int[] pondSizes(int[][] land) {
        int[] arr = new int[1000000]; //根据题目设定长度为1000*1000的数组
		int k = 0;//池塘个数
		for (int i = 0; i < land.length; i++) {
			for (int j = 0; j < land[0].length; j++) {
				if (land[i][j] == 0) {
					arr[k++] = dfs(land, i, j); //dfs遍历搜索
				}
			}
		}
	//比较菜的我只会这么复制数组
        int pond[]=new int[k];
        for(int i=0;i<k;i++)
            pond[i]=arr[i];
        Arrays.sort(pond);//从小到大排序数组
		return pond;
    }
    public static int dfs(int[][] land, int i, int j) {
		int m = land.length;
		int n = land[0].length;
		int count = 0;
		if (i < 0 || j < 0 || i >= m || j >= n || land[i][j] != 0)//判断位置是否合法以及是否为水域
			return 0;
		land[i][j] = -1;//标记为已经访问
		count++;//面积加一
		count += dfs(land, i - 1, j - 1);//遍历周围结点
		count += dfs(land, i - 1, j);
		count += dfs(land, i - 1, j + 1);
		count += dfs(land, i, j - 1);
		count += dfs(land, i, j + 1);
		count += dfs(land, i + 1, j - 1);
		count += dfs(land, i + 1, j);
		count += dfs(land, i + 1, j + 1);
		return count;
	}
}
```


并查集：
```
class Solution {
    class UF {
	int count;//连通分量数目
	int[] pre, size;//根节点数组和权值（本题是路径）数组

	public UF(int[][] land) {//初始化
		count = 0;
		int m = land.length;
		int n = land[0].length;
		pre = new int[m * n];
		size = new int[m * n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (land[i][j] == 0) {
					count++;
					pre[i * n + j] = i * n + j;
					size[i * n + j] = 1;//初试路径为1
				}
			}
	}

	public int find(int p) {//路径压缩
		while (p != pre[p]) {
			pre[p] = pre[pre[p]];
			p = pre[p];
		}
		return p;
	}

	public void union(int p, int q) {
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ)
			return;
		if (size[rootP] < size[rootQ]) {//路径长度连接
			pre[rootP] = rootQ;
			size[rootQ] += size[rootP];
			size[rootP] = 0;
		} else {//路径长度连接
			pre[rootQ] = rootP;
			size[rootP] += size[rootQ];
			size[rootQ] = 0;
		}
		count--;
	}
}
    public int[] pondSizes(int[][] land) {
		int m = land.length;
		int n = land[0].length;
		UF uf = new UF(land);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (land[i][j] == 0) {
					land[i][j] = -1;
//					这四个方向可以省略
//					if (i - 1 >= 0 && j - 1 >= 0 && land[i - 1][j - 1] == 0)
//						uf.union(i * n + j, (i - 1) * n + j - 1);
//					if (i - 1 >= 0 && land[i - 1][j] == 0)
//						uf.union(i * n + j, (i - 1) * n + j);
//					if (i - 1 >= 0 && j + 1 < n && land[i - 1][j + 1] == 0)
//						uf.union(i * n + j, (i - 1) * n + j + 1);
//					if (j - 1 >= 0 && land[i][j - 1] == 0)
//						uf.union(i * n + j, i * n + j - 1);
					if (j + 1 < n && land[i][j + 1] == 0) {
						uf.union(i * n + j, i * n + j + 1);
					}
					if (i + 1 < m && j - 1 >= 0 && land[i + 1][j - 1] == 0) {
						uf.union((i + 1) * n + j - 1, i * n + j);
					}
					if (i + 1 < m && land[i + 1][j] == 0) {
						uf.union(i * n + j, (i + 1) * n + j);
					}
					if (i + 1 < m && j + 1 < n && land[i + 1][j + 1] == 0) {
						uf.union(i * n + j, (i + 1) * n + j + 1);
					}
				}
			}
		}
		int pond[] = new int[uf.count];
		int k = 0;
		for (int i = 0; i < uf.size.length; i++) {
			if (uf.size[i] != 0) {
				pond[k++] = uf.size[i];
			}
		}
		Arrays.sort(pond);
		return pond;
    }
}
```
