### 解题思路
从左下角开始
目标元素>左下角 右移
目标元素<左下角 上移

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if(m == 0){
            return false;
        }
        int n = matrix[0].length;
        if(n == 0){
            return false;
        }
        int i = m - 1;
        int j = 0;
        while(i >= 0 && j < n){
            System.out.println(matrix[i][j]);
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                i--;
            }
            else{
                j++;
            }
        }
        return false;
    }
    /*超时
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if(m == 0){
            return false;
        }
        int n = matrix[0].length;
        if(n == 0){
            return false;
        }

        if(matrix[m - 1][n - 1] < target || matrix[0][0] > target){
            return false;
        }

        Queue<int[]> queue = new LinkedList<int[]>();
        queue.offer(new int[]{0, 0});

        while(queue.peek() != null){
            int[] pos = queue.poll();
            int i = pos[0];
            int j = pos[1];
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                continue;
            }else{
                if(i + 1 < m){
                    queue.offer(new int[]{i + 1, j});
                }
                if(j + 1 < n){
                    queue.offer(new int[]{i, j + 1});
                }
            }
        }
        return false;
    }
    */
}
```