```
class Solution {
    
    int res = 0;
    
    public int movingCount(int m, int n, int k) {
        // false未到达，true已到达和不可达
        boolean[][] visited = new boolean[m][n];
        visit(0,0,m,n,visited,k);
        return res;
    }
    
    /*
    * @r 位置的横坐标
    * @c 位置的纵坐标
    * @m 横坐标的长度
    * @n 纵坐标的长度
    * @visited 记录是否能到达
    * @k 限定条件
    */
    private void visit(int r,int c,int m,int n,boolean visited[][],int k){
        if(r >= m || c >= n || (r/10+r%10+c/10+c%10) > k || visited[r][c]){
            return;
        }
        else {
            // 向右走
            visit(r+1,c,m,n,visited,k);
            // 向下走
            visit(r,c+1,m,n,visited,k);
            res++;
            visited[r][c] = true;
        }
    }
}
```
![批注 2020-04-09 092114.png](https://pic.leetcode-cn.com/df0a042afc0bd2f4c03d348bf6375341bc38e10b3ed986b637b97553a86ab407-%E6%89%B9%E6%B3%A8%202020-04-09%20092114.png)
