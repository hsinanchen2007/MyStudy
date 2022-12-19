### 解题思路
两者的区别在于 DFS 使用 Stack 而 BFS 使用 Queue.

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        //BFS
        /*Queue<int[]> q = new LinkedList<int[]>();
        q.add(new int[]{0,0});
        int[][] visited = new int[m][n];
        int count = 0;
        while(!q.isEmpty()){
            int[] point = q.poll();
            int x = point[0];
            int y = point[1];
            if(visited[x][y] == 0){
                visited[x][y] = 1;
                int sum_x = 0, sum_y = 0, sum = 0;
                sum_x = x / 10 + x % 10;
                sum_y = y / 10 + y % 10;
                sum = sum_x + sum_y;
                if(sum <= k){
                    count++;
                    if(y + 1 < n && visited[x][y + 1] == 0)
                        q.add(new int[]{x, y + 1});
                    if(x + 1 < m && visited[x + 1][y] == 0)
                        q.add(new int[]{x + 1, y});
                    if(y - 1 >= 0 && visited[x][y - 1] == 0)
                        q.add(new int[]{x, y - 1});
                    if(x - 1 >= 0 && visited[x - 1][y] == 0)
                        q.add(new int[]{x - 1, y});
                }
            }
        }
        return count;*/
        //DFS
        Stack<int[]> s = new Stack<int[]>();
        s.push(new int[]{0,0});
        int[][] visited = new int[m][n];
        int count = 0;
        while(!s.isEmpty()){
            int[] point = s.pop();
            int x = point[0];
            int y = point[1];
            if(visited[x][y] == 0){
                visited[x][y] = 1;
                int sum_x = 0, sum_y = 0, sum = 0;
                sum_x = x / 10 + x % 10;
                sum_y = y / 10 + y % 10;
                sum = sum_x + sum_y;
                if(sum <= k){
                    count++;
                    if(y + 1 < n && visited[x][y + 1] == 0)
                        s.push(new int[]{x, y + 1});
                    if(x + 1 < m && visited[x + 1][y] == 0)
                        s.push(new int[]{x + 1, y});
                    if(y - 1 >= 0 && visited[x][y - 1] == 0)
                        s.push(new int[]{x, y - 1});
                    if(x - 1 >= 0 && visited[x - 1][y] == 0)
                        s.push(new int[]{x - 1, y});
                }
            }
        }
        return count;
    }
}
```