原以为这种题目都需要回溯，然而此题不能回溯，因为每个节点只能被遍历一次。
类似题目：79单词搜索 417太平洋大西洋水流问题
```
class Solution {
    int [][]board;
    
    int res=0;
    int [][]dirs={{1,0},{-1,0},{0,-1},{0,1}};
    int rows,cols;
    public int movingCount(int m, int n, int k) {
        rows=m;
        cols=n;
        
        board=new int[m][n];
        dfs(0,0,k);
        
        return res;
    }
    
    void dfs(int x,int y,int k){
        
        int curSum=sum(x,y);
        //System.out.println("curSum:"+curSum+" x:"+x+" y:"+y);
        if(curSum>k){
            return;
        }
        if(board[x][y]==0){
           
            res++;
        }
        board[x][y]=1;
        for(int []dir:dirs){
            int new_x=x+dir[0];
            int new_y=y+dir[1];
           // System.out.println("new_x:"+new_x+" new_y:"+new_y);
            if(new_x>=0&&new_x<rows&&new_y>=0&&new_y<cols&&board[new_x][new_y]==0){
                dfs(new_x,new_y,k);
                //board[x][y]=0;
            }
        }
        //board[x][y]=0;
    }
    public int sum(int x,int y){
        int sum=0;
        while(x!=0){
            sum+=x%10;
            x/=10;
        }
        while(y!=0){
            sum+=y%10;
            y/=10;
        }
        
        return sum;

    }
}
```
