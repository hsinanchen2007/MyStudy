class Solution {
    public boolean exist(char[][] board, String word) {
        
        int n1 = board.length;
        int n2 = board[0].length;
        int n = word.length();
        boolean result = false;
        boolean visited[][] = new boolean[n1][n2];
        
        if(word.length() == 0 || n1*n2 <n)
        {
            return false;
        }
        
        char first = word.charAt(0);
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(first == board[i][j])
                {
                    visited[i][j] = true;
                    result = search(board,i,j,word.substring(1,n),n1,n2,visited);
                    if(result == true)
                    {
                        return true;
                    }
                    visited[i][j]=false;
                }
            }
        }
        return false;
        
    }
    
    public boolean search(char[][] board,int i,int j,String word,int n1,int n2,boolean[][] visited)
    {   
        int n = word.length();

        if(word.length() == 0)
        {
            return true;
        }
        else
        {
            if(i-1>=0 && board[i-1][j] == word.charAt(0) && visited[i-1][j]==false)
            {
                visited[i-1][j]=true;
                boolean result=search(board,i-1,j,word.substring(1,n),n1,n2,visited);
                visited[i-1][j]=false;
                if(result == true)
                {
                    return true;
                }
            }
            if(i+1<n1 && board[i+1][j] == word.charAt(0) && visited[i+1][j]==false)
            {
                visited[i+1][j]=true;
                boolean result = search(board,i+1,j,word.substring(1,n),n1,n2,visited);
                visited[i+1][j]=false;
                if(result == true)
                {
                    return true;
                }
            }
            if(j-1>=0 && board[i][j-1] == word.charAt(0) && visited[i][j-1]==false)
            {
                visited[i][j-1]=true;
                boolean result = search(board,i,j-1,word.substring(1,n),n1,n2,visited);
                visited[i][j-1]=false;
                if(result == true)
                {
                    return true;
                }
            }
            if(j+1<n2 && board[i][j+1] == word.charAt(0) && visited[i][j+1]==false)
            {
                visited[i][j+1]=true;
                boolean result = search(board,i,j+1,word.substring(1,n),n1,n2,visited);
                visited[i][j+1]=false;
                if(result == true)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
}
