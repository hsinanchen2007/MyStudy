我的思路是用一个boolean数组去存储该值是否进行改变，这样就可以只遍历一次数组，在判断一个位置的时候首先判断是否越界，然后去判断boolean数组的该位置是否为true，为true就代表这个位置更改过了，就传回更改之前的值。这种思路就是时间复杂度较低，空间复杂度较高，这种不算是原地算法。
```java
class Solution {
    int[][]board;
    boolean[][]flag;
    public void gameOfLife(int[][] board) {
        this.board=board;
       flag=new boolean[board.length][board[0].length];
       for(int i=0;i<board.length;i++)
       {
           for(int j=0;j<board[0].length;j++)
           {
               int type=board[i][j];
               int newType=isAlive(i,j);
               if(type!=newType)
               {
                   board[i][j]=board[i][j]==1?0:1;
                   flag[i][j]=true;
                       
               }
           }
       }
    }
    public int isAlive (int i,int j)
    {
       int type=board[i][j];
        int times=isAliveLast(i-1,j)+isAliveLast(i+1,j)+isAliveLast(i,j+1)
            +isAliveLast(i,j-1)+isAliveLast(i-1,j-1)+isAliveLast(i+1,j+1)+
            isAliveLast(i-1,j+1)+isAliveLast(i+1,j-1);
        if(type==0)
        {
         if(times==3)
             return 1;
        else
           return 0;     
        }
        else
        {
            if(times<2||times>3)
                return 0;
            else 
                return 1;
        }
    }
    public int isAliveLast(int i ,int j)
    {
        if(i<0||i>=board.length||j<0||j>=board[0].length)
            return 0;
        //改变过了,返回之前的。
        if(flag[i][j])
            return board[i][j]==1?0:1;
        else
            return board[i][j];
    }
}
```
