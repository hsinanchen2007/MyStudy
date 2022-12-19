方法一：BFS
```java
class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    public int movingCount(int m, int n, int k) {
        int count = 1;
        boolean[][] record = new boolean[m][n];
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        q.offer(0);
        record[0][0] = true;
        while(!q.isEmpty()){
            int a = q.poll(), b = q.poll();
            for(int[] l: dir){
                int newa = a+l[0], newb = b+l[1];
                if(newa>=0 && newa<m && newb>=0 && newb<n && compute(newa,newb)<=k && !record[newa][newb]){
                    q.offer(newa);
                    q.offer(newb);
                    count++;
                    record[newa][newb] = true;
                }
            }
        }
        return count;
    }
    public int compute(int x,int y){
        int result = 0;
        while(x>0){
            result += x%10;
            x /= 10;
        }
        while(y>0){
            result += y%10;
            y /= 10;
        }
        return result;
    }
}
```
方法二：DFS
```java
class Solution {
    boolean[][] record;
    public int movingCount(int m, int n, int k) {
        record = new boolean[m][n];
        return dfs(m,n,0,0,k);
    }
    public int dfs(int m,int n,int i,int j,int k){
        if(i<0 || i>=m || j<0 || j>=n || compute(i,j)>k || record[i][j]){
            return 0;
        }
        record[i][j] = true;
        return 1+dfs(m,n,i+1,j,k)+dfs(m,n,i,j+1,k);
    }
    public int compute(int x,int y){
        int result = 0;
        while(x>0){
            result += x%10;
            x /= 10;
        }
        while(y>0){
            result += y%10;
            y /= 10;
        }
        return result;
    }
}
```