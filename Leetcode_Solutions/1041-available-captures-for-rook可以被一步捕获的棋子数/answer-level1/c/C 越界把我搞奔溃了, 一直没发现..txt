### 解题思路
随便乱写的....

### 代码

```c

int numRookCaptures(char** board, int boardSize, int* boardColSize)
{
	int count = 0, i = 0, j = 0, k = 0, z = 0, flag = 0;
	
	for(i = 0; i < boardSize; i++)
	{
		for(j = 0; j < *boardColSize; j++)
		if(board[i][j] == 'R')
		{
			flag = 1;
			break;
		}
		
		
		if(flag)
		break;
	} 
	
	for(k = i, z = j; z < *boardColSize; z++)
	{
		if(board[k][z] == 'B')
		break;
		
		if(board[k][z] == 'p')
		{
			count++;
			break; 
		} 
	} 
	
	for(k = i, z = j; z >= 0; z--)
	{
		if(board[k][z] == 'B')
		break;
		
		if(board[k][z] == 'p')
		{
			count++;
			break; 
		} 
	} 
	
	for(k = i, z = j; k >= 0; k--)
	{
		if(board[k][z] == 'B')
		break;
		
		if(board[k][z] == 'p')
		{
			count++;
			break; 
		} 
	} 
	
	for(k = i, z = j; k < boardSize; k++)
	{
		if(board[k][z] == 'B')
		break;
		
		if(board[k][z] == 'p')
		{
			count++;
			break; 
		} 
	} 
	
	return count; 

}
```