```c
int numRookCaptures(char** board, int boardSize, int* boardColSize)
{
    int total = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    
    for( i = 0;i < *boardColSize; i++)
    {

        for(j = 0; j <*boardColSize;j++)
        {
            if(board[i][j] == 'R')
            {
                 flag = 1;
                break ;
               
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
    printf("%d %d\n",i,j)；

        for( int m = 0;m<*boardColSize;m++)
        {
            if(j + m > 7)
            {
                break;
            }
            if(board[i][j+m] == 'B')
            {
                break;
            }
            else if(board[i][j+m] == 'p')
            {
                total++;
                break;
            }
            
        }
        
        for( int m = 0;m<*boardColSize;m++)
        {
            if(i + m > 7)
            {
                break;
            }
            if(board[i+m][j] == 'B')
            {
                break;
            }
            else if(board[i+m][j] == 'p')
            {
                total++;
                break;
            }
            
        }
        
        for( int m = 0;m<*boardColSize;m++)
        {
            if(j -m <0 )
            {
                break;
            }
            if(board[i][j - m] == 'B')
            {
                break;
            }
            else if(board[i][j - m] == 'p')
            {
                total++;
                break;
            }
            
        }
        
        for( int m = 0;m<*boardColSize;m++)
        {
            if(i -m <0 )
            {
                break;
            }
            if(board[i-m][j] == 'B')
            {
                break;
            }
            else if(board[i-m][j] == 'p')
            {
                total++;
                break;
            }
            
        }
        

    return total ;

}
```