```
class Solution {//98%
    
    int counter=2;//一共有多少步需要走，包括起点终点
    int sum=0;//最终结果
    boolean ff[][];//标记该处是否走过
    
    public int uniquePathsIII(int[][] gr) {
        
        int x=0,y=0;
        ff=new boolean[gr.length][gr[0].length];
        
        for(int i=0;i<gr.length;i++){//找出开始位置
            for(int j=0;j<gr[0].length;j++){
                
                if(gr[i][j]==0)counter++;
                else if(gr[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }

        go(gr,x,y);//开始搜索路径

        return sum;
        
    }
    private void go(int[][] gr,int x,int y){
        if(x<0||x>=gr.length||y<0||y>=gr[0].length||gr[x][y]==-1||ff[x][y])return;
        
        ff[x][y]=true;//标记已经走过
        counter--;

        if(counter==0&&gr[x][y]==2){//到达终点
            sum++;
            
        }else if(gr[x][y]!=2){//四个方向试探
            go(gr,x+1,y);
            go(gr,x-1,y);
            go(gr,x,y+1);
            go(gr,x,y-1);
        }
        
        ff[x][y]=false;//恢复已经走过
        counter++;//
        // [[1,0,0,0]
        // ,[0,0,0,0]
        // ,[0,0,2,-1]]

    }
}
```
