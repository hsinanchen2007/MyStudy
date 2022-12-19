```
class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        Deque<Integer> pre = new LinkedList<>();
        
        for (int i = 0; i < matrix[0].length; i++) {
            pre.offerLast(matrix[0][i]);
        }
        
        for (int i = 1; i < matrix.length; i++) {
           if (!consume(pre, matrix[i])) {
               return false;
           }
        }
        return true;
    }
    
    boolean consume(Deque<Integer> pre, int[] arr) {
        Deque<Integer> cur = new LinkedList<>();
        pre.pollLast();
        for (int i = arr.length - 1; i >= 1; i--) {
            int temp = pre.pollLast();
            if (temp != arr[i]) {
                return false;
            }
            cur.offerFirst(temp);
        }
        cur.offerFirst(arr[0]);
        while (!cur.isEmpty()) {
            pre.offerLast(cur.pollFirst());
        }       
        return true;
    }
}
```
