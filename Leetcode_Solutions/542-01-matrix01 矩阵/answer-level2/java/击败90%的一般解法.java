### 解题思路
判断某个点最近的零距离，换个说法就是从距离零开始检索，在某个距离上最先找到零就返回那个距离即可。详细可点击[https://blog.csdn.net/qq_23134039/article/details/103423528]()

### 代码

```java
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int [][] nums = new int[matrix.length][matrix[0].length];
        for(int m=0;m<matrix.length;m++) {
        	for(int n=0;n<matrix[0].length;n++) {
        		nums[m][n]=testnums(matrix,m,n);
        	}
        }
		return  nums;
    }
	
	static int testnums(int[][]matrix,int x,int y) {
		int w=matrix.length;
		int h=matrix[0].length;
		if(matrix[x][y]==0) {
			return 0;
		}
		for(int i=1;i<Math.max(w, h);i++) {
			for(int m=0;m<=i;m++) {
				int n=((x+m<w)&&(y+i-m<h)?matrix[x+m][y+i-m]:1)&
						((x-m>-1)&&(y+i-m<h)?matrix[x-m][y+i-m]:1)&
						((x+m<w)&&(y-i+m>-1)?matrix[x+m][y-i+m]:1)&
						((x-m>-1)&&(y-i+m>-1)?matrix[x-m][y-i+m]:1);
				if (n==0) return i;
			}
		}
		return 0;
    }
}
```