![image.png](https://pic.leetcode-cn.com/7347b699c11915d9a71f1cc7a2e630a71c4a63f210b833697e7457c21951f976-image.png)
```
class Solution {
    public void rotate(int[][] matrix) {
        int i, j, k, n, x, y, t;
        int[] point;
        
        n = matrix.length;
        for(i = 0; i < n/2; i++) {
        	for(j = i; j < n - 1 - i; j++) {
            	x = i;
            	y = j;
            	t = matrix[x][y];
            	for(k = 0; k < 3; k++) {
            		point = lastPoint(n, x, y);
            		matrix[x][y] = matrix[point[0]][point[1]];
            		x = point[0];
            		y = point[1];
            	}
            	matrix[x][y] = t;
        	}
        }
    }

	private int[] lastPoint(int n, int r, int c) {
		int[] answer = new int[2];
		answer[0] = n - 1 - c;
		answer[1] = r;
		return answer;
	}
}
```
