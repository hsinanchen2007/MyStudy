### 解题思路
打卡第二天，看题解，写答案

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        /*
         关键条件：机器人每次只能向左、右、上、下移动一格，
         并且行坐标和列坐标的数位之和大于K的格子。
         根据题解说明只能用BFS(广度搜索)和DFS(深度搜索)这两种进行解答
         */
        int si=0 ;
        int sj=0 ;
        boolean[][] flag= new boolean[m][n];
        return dfs(0,0,si,sj,k,m,n,flag);
    }
    public int dfs(int i, int j, int si, int sj, int k, int m, int n,boolean[][] flag){
        // 越界情况递归结束
        if(i>=m||j>=n||(si+sj)>k||flag[i][j]){
            return 0;
        }
        flag[i][j]=true;
        return 1+dfs(i+1,j,sumij(i+1),sumij(j),k,m,n,flag)+dfs(i,j+1,sumij(i),sumij(j+1),k,m,n,flag);
    }
    public int sumij(int x){
        int sum = 0;
        while(x>9){
            sum = sum+x%10;
            x=x/10;
        }
        sum = sum+x;
        return sum;
    }
}
```