### 解题思路
暴力循环，分为上、下、左、右循环，遇到循环不下去则停止

## 需要注意

1. 起始如果数据y=1那么需要向下
2. 各边界条件判断

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {

		List<Integer> l = new ArrayList<Integer>();
		if(matrix.length==0)
			return l;
		
		l.add(matrix[0][0]);
		find(matrix,l,0,0,matrix[0].length==1?2:1);
		
		return l;
	}

	private void find(int[][] matrix, List<Integer> l, int i, int j,int direct) {
		
		if(direct == 1) {
			//to i,y-1-i, direct=2
			int k = matrix[0].length-1-i;
			if(j==k) {
				return ;
			}
			for(int x=j+1;x<=k;x++) {
				l.add(matrix[i][x]);
			}
			find(matrix,l,i,k,2);
		}else if (direct == 2) {
			// to x-1-i,j, direct=3
			int k = matrix.length-1-i;
			if(i==k){
				return ;
			}
			for(int x=i+1;x<=k;x++) {
				l.add(matrix[x][j]);
			}
			find(matrix,l,k,j,3);
		}else if (direct ==3 ) {
			// to i,y-1-j direct = 4
			int k = matrix[0].length-1-j;
			if (j==k){
				return ;
			}
			for(int x=j-1;x>=k;x--) {
				l.add(matrix[i][x]);
			}
			find(matrix,l,i,k,4);
		}else {// 4
			// to x-1-i+1,y ,direct =1
			int k = matrix.length-1-i+1;
			if (i==k){
				return ;
			}
			for(int x=i-1;x>=k;x--) {
				l.add(matrix[x][j]);
			}
			find(matrix,l,k,j,1);
		}
		
	}
}
```