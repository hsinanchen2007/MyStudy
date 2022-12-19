### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int[] P;
	// 剩余的线
	int count;
	public int makeConnected(int n, int[][] connections) {
		P=new int[n];
		count=connections.length;
		// 初始化
		for(int i=0;i<n;i++) {
			P[i]=i;
		}
		for(int i=0;i<connections.length;i++) {
			union(connections[i][0],connections[i][1]);
		}
		if(count<n-(connections.length-count+1)) {
			// 如果剩余的线小于剩余的电脑数
			return -1;
		}else {
			return n-(connections.length-count+1);
		}
	}

	
	private int find(int x) {
		return P[x] == x ? x : (P[x] = find(P[x]));	//路径压缩
	}
	
	private void union(int x,int y) {
		int xRoot=find(x);
		int yRoot=find(y);
		if(xRoot!=yRoot) {
			P[xRoot]=yRoot;
			count--;
		}
	}
	
}
```