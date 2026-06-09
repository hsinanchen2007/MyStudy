![image.png](https://pic.leetcode-cn.com/07d5ef87edc4508d59a07aad9c05adf060c2709f61c63b34f55ea268561ac2dd-image.png)

```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int i, m, n, size, row, col;
        List<Integer> answer;
        int[] point;
        int[][] pointSeq;
        
        answer = new ArrayList<>();
        if(matrix.length == 0 || matrix[0] == 0)
            return answer;
        m = matrix.length;
        n = matrix[0].length;   
        size = m * n;
        pointSeq = getPointSeq(m, n);

        for(i = 0; i < size; i++){            
            point = pointSeq[i];
            row = point[0];
            col = point[1];
            answer.add(matrix[row][col]);
        }
        return answer;
    }
    
    private int[][] getPointSeq(int m, int n){
        int[][] answer = new int[m*n][2];
        int[] point;
        int length, delta, i, r, c, index;
        
        delta = 0;
        index = 0;
        while(m > 0 && n > 0){
            r = 0;
            c = 0;
            if(m == 1)
                length = n;
            else if(n == 1)
                length = m;
            else
                length = 2 * (m + n) - 4;
            for(i = 0; i < length; i++){
                answer[index][0] = r + delta;
                answer[index][1] = c + delta;
                index++;
                point = nextPoint(r, c, m, n);
                r = point[0];
                c = point[1];
            }
            delta++;
            m = m - 2;
            n = n - 2;
        }
        return answer;
    }

	private int[] nextPoint(int r, int c, int m, int n) {
		int[] answer = new int[2];
		
		if(r == 0 && c < n - 1) {
			answer[0] = r;
			answer[1] = c + 1;
			return answer;
		}
		if(r < m - 1 && c == n - 1) {
			answer[0] = r + 1;
			answer[1] = c;
			return answer;
		}
		if(r == m - 1 && c > 0) {
			answer[0] = r;
			answer[1] = c - 1;
			return answer;
		}if(r > 0 && c == 0) {
			answer[0] = r - 1;
			answer[1] = c;
			return answer;
		}
		return new int[] {0, 0};
	}
        
}
```
