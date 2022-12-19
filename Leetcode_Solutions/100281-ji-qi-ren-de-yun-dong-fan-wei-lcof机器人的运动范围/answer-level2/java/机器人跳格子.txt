### 解题思路
1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，
	     返回1 + 4 个方向的探索值之和。
	2.探索时，判断当前节点是否可达的标准为：
	1）当前节点在矩阵内；
	2）当前节点未被访问过；
	3）当前节点满足limit限制。

### 代码

```java
class Solution {
    public static void main(String[] args) {
		int count = movingCount(2, 3, 1);
		System.out.println("有效个数:"+count);
	}
    public static int movingCount(int m, int n, int k) {
      // 定义一个布尔类型的二维数组判断当前节点是否被访问过
		boolean[][] visited = new boolean[m][n];
		return countingSteps(m, n, k, 0, 0, visited);
    }
    /*
	 * 使用递归方法获取有效的节点个数
	 */
	private static int countingSteps(int m, int n, int k, int r, int c, boolean[][] visited) {
		if(r<0||r>=m||c<0||c>=n||visited[r][c]||bitSum(r)+bitSum(c)>k) {
			return 0;
		}
		visited[r][c] = true;
		return countingSteps(m, n, k, r-1, c, visited)+
			   countingSteps(m, n, k, r+1, c, visited)+
			   countingSteps(m, n, k, r, c-1, visited)+
			   countingSteps(m, n, k, r, c+1, visited)+
			   1;
	}

	/*
	 * 将当前的一个未知位数分解开来并相加
	 */
	private static int bitSum(int r) {
		int count = 0;
		while (r != 0) {
			count += r % 10;
			r /= 10;
		}
		return count;
	}
    
}
```