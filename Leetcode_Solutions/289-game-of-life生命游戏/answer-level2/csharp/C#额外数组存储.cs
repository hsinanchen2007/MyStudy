public class Solution {
    public void GameOfLife(int[][] board) 
    {
        if(board.Length < 1) return;
        int m = board.Length;
        int n = board[0].Length;
        int[] mArray = new int[]{-1,0,1,0,-1,-1,1,1};
        int[] nArray = new int[]{0,-1,0,1,-1,1,-1,1};

        int[,] resultArray = new int[m, n];

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                resultArray[i,j] = board[i][j];
            }
        }
        int num = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                num = 0;
                for(int k = 0 ; k < 8 ; k++)
                {
                    int newM = i + mArray[k];
                    int newN = j + nArray[k];
                    if(newM < 0 || newM >= m || newN < 0 || newN >= n)
                    {
                        continue;
                    }
                    if(board[newM][newN] == 1)
                       num++; 
                }
                if(num < 2 && board[i][j] == 1)
                {
                    resultArray[i,j] = 0;
                }
                else if(num >=2 && num <=3 && board[i][j] == 1)
                {
                    resultArray[i,j] = 1;
                }
                else if( num > 3 && board[i][j] == 1)
                {
                     resultArray[i,j] = 0;
                }
                else if(num == 3 && board[i][j] == 0)
                {
                     resultArray[i,j] = 1;
                }
               
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                board[i][j] = resultArray[i,j];
            }
        }
    }
}