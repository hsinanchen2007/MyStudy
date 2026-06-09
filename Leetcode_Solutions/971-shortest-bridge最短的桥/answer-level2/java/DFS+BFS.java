![image.png](https://pic.leetcode-cn.com/237ad3e2c2311fbabf667271fcb3ad6e308d5752b330c7af66c350f6d959c4bf-image.png)

```
class Solution {
    public int shortestBridge(int[][] A) {
        Queue<int[]> queue;
        int i, j;
        int[] next;

        queue = new LinkedList<>();
        H:
        for(i = 0; i < A.length; i++)    
            for(j = 0; j < A[0].length; j++)
        		if(A[i][j] == 1) {
        			storeNext(A, i, j, queue);
        			break H;
        		}
        while(true) {
        	next = queue.remove();
        	i = next[0];
        	j = next[1];
        	if(check(A, i + 1, j, i, j, queue)
        		|| check(A, i - 1, j, i, j, queue)
        		|| check(A, i, j + 1, i, j, queue)
        		|| check(A, i, j - 1, i, j, queue))
        		return -A[i][j];
        	}
        }
    
    private boolean check(int[][] A, int i1, int j1, int i2, int j2, Queue<int[]> queue) {
    	if(i1 >= 0 && i1 < A.length && j1 >= 0 && j1 < A[0].length) {
    		if(A[i1][j1] == 0) {
    			A[i1][j1] = A[i2][j2] - 1;
    			queue.add(new int[]{i1, j1});
    			return false;
    		}
    		if(A[i1][j1] == 1)
    			return true;
    	}
		return false;
	}
    
    private void storeNext(int[][] A, int i, int j, Queue<int[]> queue) {
    	if(i >= 0 && i < A.length && j >= 0 && j < A[0].length) {
    		if(A[i][j] == 1) {
    			A[i][j] = 2;
    			storeNext(A, i + 1, j, queue);
    			storeNext(A, i - 1, j, queue);
    			storeNext(A, i, j + 1, queue);
    			storeNext(A, i, j - 1, queue);
    		}else if(A[i][j] == 0) {
    			A[i][j] = -1;
    			queue.add(new int[]{i, j});
    		}
    	}
    }
}
```
