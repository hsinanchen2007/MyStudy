### 解题思路
拉布拉多的思路
回溯
判断是否是正确的时候，因为我们是每一行来做遍历，发射
那么我们只需要判断左上跟右上是否存在Q即可，并且只判断列上是否存在Q，因为行上因为每次只发射一个，发射完就推进到下一行，那么在当前行上肯定是没有其他Q的。

### 代码

```java
class Solution {                                                    
    List<List<String>> res=new ArrayList<>();                                    
    public List<List<String>> solveNQueens(int n) {                              
        List<String> temp=new ArrayList<>();                                     
        char[][] board=new char[n][n];                                           
        for(int i=0;i<n;i++)                                                     
            for(int j=0;j<n;j++)                                                 
                board[i][j]='.';                                                 
                                                                                 
        helper(board,0,temp);                                                    
        return res;                                                              
    }                                                                            
                                                                                 
    public List<String> charToList(char[][] board)                               
    {                                                                            
        int len=board.length;                                                    
        List<String> res=new ArrayList<>();                                      
        for(int i=0;i<len;i++)                                                   
            res.add(String.valueOf(board[i]));                                   
        return res;                                                              
    }                                                                            
    public boolean isValid(char[][] board,int row, int column)                   
    {                                                                            
        int len=board.length;                                                    
        for(int i=0;i<len;i++)                                                   
        {                                                                        
            if (board[i][column]=='Q')                                           
                return false;                                                    
        }                                                                        
        for (int i=row-1,j=column-1;i>=0 && j>=0;i--,j--)                        
            if (board[i][j]=='Q')                                                
                return false;                                                    
                                                                                 
        for (int i=row-1,j=column+1;i>=0 && j<len;j++,i--)                       
            if (board[i][j]=='Q')                                                
                return   false;                                                  
                                                                                 
        return true;                                                             
    }                                                                            
                                                                                 
    public void helper(char[][] board, int start, List<String> temp)             
    {                                                                            
        int len=board.length;                                                    
        if(start==len)                                                           
        {                                                                        
            res.add(new ArrayList<>(charToList(board)));                         
            return;                                                              
        }                                                                        
        for(int j=0;j<len;j++)                                                   
        {                                                                        
            if(isValid(board,start,j))                                           
            {                                                                    
                board[start][j]='Q';                                             
                helper(board,start+1,temp);                                      
                board[start][j]='.';                                             
                                                                                 
            }                                                                    
        }                                                                        
                                                                                 
    }                                                                            
}                                                                                
                                                                                 
```