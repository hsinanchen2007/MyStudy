能走的通的就直接标记，然后计数加一；
不能走通的也标记，计数不变;

```java
class Solution {
    int cols;
    int rows;
    boolean[][] marked;
    int sign;
    int sum=0;
    int[][] directions={{0,1},{1,0},{0,-1},{-1,0}};

    public int movingCount(int m, int n, int k) {
        cols=n;
        rows=m;
        sign=k;
        marked=new boolean[m][n];
        DFS(0,0);
        return sum;
    }
    //判断是否在方格内
    public boolean isArea(int x,int y){
        return x>=0&&x<rows&&y>=0&&y<cols;
    }
    //深搜
    public void DFS(int x,int y){
        if(canEnter(x,y)){
            marked[x][y]=true;
            sum++;
        }else{
            marked[x][y]=true;
            return;
        }
        for(int k=0;k<4;k++){
            int newX=x+directions[k][0];
            int newY=y+directions[k][1];
            if(isArea(newX,newY)&&!marked[newX][newY]){
                DFS(newX,newY);
            }
        }
    }
//判断是否能进入
    public boolean canEnter(int x,int y){
        int temp=0;
        while(x!=0||y!=0){
            temp+=x%10;
            temp+=y%10;
            x/=10;
            y/=10;
        }
        if(temp>sign) return false;
        return true;
    }

}
```