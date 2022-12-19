### 解题思路
### dfs/bfs

### 代码

```java
class Solution {
    int m, n, k;
    boolean[][] visited;
    public int movingCount(int m, int n, int k) {

        //方法1：递推法：搜索方向为向右和向下，vis[i][j]=vis[i-1][j] or vis[i][j-1]:即只要有上和左 中有一个可达，当前格子就可达，
        // int steps=1;
        // int[][] vis=new int[m][n];//定义格子是否可达
        // vis[0][0]=1;//初始状态
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if((i==0&&j==0)||counts(i)+counts(j)>k){
        //             continue;
        //         }
        //         if(i-1>=0) vis[i][j]|=vis[i-1][j];
        //         if(j-1>=0) vis[i][j]|=vis[i][j-1];
        //         steps+=vis[i][j];
        //     }
        // }
        // return steps;

        //方法2：广度优先算法
        // boolean visited[][]=new boolean[m][n];
        // int ans=0;
        // Queue<int []>queue=new LinkedList<int[]>();
        // queue.add(new int[]{0,0,0,0});//初始值入队
        // while(!queue.isEmpty()){
        //     int[] x=queue.poll();
        //     int i=x[0];int j=x[1];int si=x[2];int sj=x[3];
        //     if(i>=m||j>=n||si+sj>k||visited[i][j]) continue;
        //     visited[i][j]=true;
        //     ans++;
        //     queue.add(new int[]{i+1,j,(i+1)%10!=0 ?si+1:si-8,sj});
        //     queue.add(new int[]{i,j+1,si,(j+1)%10!=0? sj+1:sj-8});
        // }
        // return ans;

        //最优方法；深度优先搜索 dfs
        int ans=0;
        this.m=m;this.n=n;this.k=k;
        visited=new boolean[m][n];//定义格子是否已经访问过了
        return dfs(0,0,0,0);//i，j,以及其数字相加之和



    }
    public int dfs(int i,int j,int si,int sj){ //往右和下搜索 ans=1+下方搜索+右边索索
        if(i>=m||j>=n||si+sj>k||visited[i][j]) return 0;
        visited[i][j]=true;
        return 1+dfs(i+1,j,(i+1)%10!=0 ?si+1:si-8,sj)+dfs(i,j+1,si,(j+1)%10!=0? sj+1:sj-8);
    }
    public int counts(int m){
        int ans=0;
        while(m>0){
            ans+=m%10;
            m=m/10;
        }
        return ans;
    }

}
```