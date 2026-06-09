https://baike.baidu.com/item/%E5%9F%BA%E4%BA%8E%E6%A0%87%E7%AD%BE%E4%BC%A0%E6%92%AD%E7%9A%84%E7%A4%BE%E5%9B%A2%E5%8F%91%E7%8E%B0%E7%AE%97%E6%B3%95%28LPA%29/22130359?fr=aladdin


public int numIslands(char[][] grid)
	{
		for(int i = 0;i<grid.length;i++) 
		{
			for(int j =0 ;j<grid[i].length;j++) 
			{
				if(grid[i][j] == '1') 
				{
					LPA(i,j,grid);
					grid[i][j] = '1';
				}
			}
		}
		
		int count = 0;
		for(int i = 0;i<grid.length;i++) 
		{
			for(int j =0 ;j<grid[i].length;j++) 
			{
				if(grid[i][j] == '1') 
				{
					count++;
				}
			}
		}
		return count;
    }
	
	private void LPA(int i,int j,char[][] grid) 
	{
		//向上传播标签 0
		if(i>0) 
		{
			if(grid[i-1][j] == '1') 
			{
				grid[i-1][j] = '*';
				LPA(i-1,j,grid);
			}
		}
		//向下传播标签
		if(i<grid.length-1) 
		{
			if(grid[i+1][j] == '1') 
			{
				grid[i+1][j] = '*';
				LPA(i+1,j,grid);
			}
		}
		//向左传播标签
		if(j>0) 
		{
			if(grid[i][j-1] == '1') 
			{
				grid[i][j-1] = '*';
				LPA(i,j-1,grid);
			}
		}
		//向右传播标签
		if(j<grid[0].length-1) 
		{
			if(grid[i][j+1] == '1') 
			{
				grid[i][j+1] = '*';
				LPA(i,j+1,grid);
			}
		}
		
	}

