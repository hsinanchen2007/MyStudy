### 解题思路
第一个bfs，将其中一个岛渲染成2，并记录边界，只要某点四个连接点有一个为0，就是边界，添加进队列，用于第二个bfs的搜索。第二个bfs同时从各个边界出发，记录路径即可。

### 代码

```java
class Solution {
    public int shortestBridge(int[][] A) {
        if (A.length == 0){
            return 0;
        }
        Queue<Integer> queue = new LinkedList<>();
        outterLoop: for (int i = 0;i<A.length;i++){
            for (int j = 0;j<A[0].length;j++){
                if (A[i][j] == 1){

                    A[i][j] = 2;
                    queue.add(i*A[0].length + j);
                    help(A, queue);
                    break outterLoop;
                }
            }}
        int cnt = bfs(A, queue);
        System.out.println(cnt);
        return cnt;
    }
        public void help(int[][] A, Queue<Integer> queue){
        Queue<Integer> queue1 = new LinkedList<>();
        queue1.add(queue.poll());

        int rows = A.length;
        int cols = A[0].length;

        while (!queue1.isEmpty()){
            List<Integer> list = new LinkedList<>();
            while (!queue1.isEmpty()){
                list.add(queue1.poll());
            }
            for (int cur : list){
                int row = cur/cols;
                int col = cur%cols;
                if (row-1 >= 0 && A[row-1][col] == 1){
                    A[row-1][col] = 2;
                    queue1.add((row-1)*cols+col);
                }
                if (row+1<rows && A[row+1][col] == 1){
                    A[row+1][col] = 2;
                    queue1.add((row+1)*cols+col);
                }
                if (col-1 >= 0 && A[row][col-1] == 1){
                    A[row][col-1] = 2;
                    queue1.add(row*cols+col-1);
                }
                if (col+1 < cols && A[row][col+1] == 1){
                    A[row][col+1] = 2;
                    queue1.add(row*cols+col+1);
                }
                if ((row-1 >= 0 && A[row-1][col] == 0) || (row+1<rows && A[row+1][col] == 0) ||
                        (col-1 >= 0 && A[row][col-1] == 0 || (col+1 < cols && A[row][col+1] == 0))){
                    queue.add(row*cols+col);
                }
            }
        }
    }
    public int bfs(int[][] A, Queue<Integer> queue){
        int cnt = 0;
        int cols = A[0].length;
        int rows = A.length;

        while (!queue.isEmpty()){
            List<Integer> list = new LinkedList<>();
            while (!queue.isEmpty()){
                list.add(queue.poll());
            }
            int flag = 0;
            for (int cur :list){
                int row = cur/cols;
                int col = cur%cols;
                if ((row-1>=0 && A[row-1][col] == 1) || (row+1<rows && A[row+1][col] == 1) ||
                        (col-1 >=0 && A[row][col-1] == 1) || (col+1 < cols && A[row][col+1] == 1)){
                    return cnt;
                }
                else if ((row-1>=0 && A[row-1][col] == 0) || (row+1<rows && A[row+1][col] == 0) ||
                        (col-1 >=0 && A[row][col-1] == 0) || (col+1 < cols && A[row][col+1] == 0)){
                    flag = 1;
                    if (row-1 >= 0 && A[row-1][col] == 0){
                        A[row-1][col] = 2;
                        queue.add((row-1)*cols+col);
                    }
                    if (row+1<rows && A[row+1][col] == 0){
                        A[row+1][col] = 2;
                        queue.add((row+1)*cols+col);
                    }
                    if (col-1 >= 0 && A[row][col-1] == 0){
                        A[row][col-1] = 2;
                        queue.add(row*cols+col-1);
                    }
                    if (col+1 < cols && A[row][col+1] == 0){
                        A[row][col+1] = 2;
                        queue.add(row*cols+col+1);
                    }
                }
            }

            if (flag == 1){
                cnt++;
            }
        }
        return cnt;
    }
}
```