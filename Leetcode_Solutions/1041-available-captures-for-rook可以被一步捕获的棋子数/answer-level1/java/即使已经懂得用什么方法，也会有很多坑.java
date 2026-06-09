### 解题思路
先找到  车的位置，然后再沿着四个方向找 卒或象。（笨方法）

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        
        int i =0,j=0,num=0;
        int flag=0,flag_i=0,flag_j=0;
        for(i=0;i<8;i++)
        {     
            for(j=0;j<8;j++)
            {
                if( board[i][j] == 'R' )
                {
                    flag =1;
                    flag_i=i;
                    flag_j=j;
                    break;
                }      
            }
            if(flag==1)
                break;
         }
       System.out.println(i+","+j);
                      while(i!=0)
                    {
                        if( board[i][j] == 'p' )
                        {
                            num++;                 
                              break; 
                        } 
                        else if(board[i][j] == 'B') break;
                        else
                            i=i-1;
                    }
                    i= flag_i;

                    while(i<8)
                    {
                        if( board[i][j] == 'p'  )
                        {
                            num++;   
                           
                             break; 
                        }
                        else if(board[i][j] == 'B') break;
                        else
                            i=i+1;
                    }
                    i= flag_i;

                    System.out.println(i+","+j);
                    
                    while(j!=0)
                    {           
                        if( board[i][j] == 'p' )
                        {
                            num++;   
                            j= flag_j;
                             break; 
                        }
                        else if(board[i][j] == 'B') break;
                        else
                            j=j-1;
                    }
                    j= flag_j;
                        
                    while(j<8)
                    {
                        if( board[i][j] == 'p' )
                        {
                            num++; 
                            j= flag_j;
                            break;    
                        }
                        else if(board[i][j] == 'B') break;
                         else
                            j=j+1; 
                    }
                    j= flag_j;

       
            
        return num;
    }

}
```