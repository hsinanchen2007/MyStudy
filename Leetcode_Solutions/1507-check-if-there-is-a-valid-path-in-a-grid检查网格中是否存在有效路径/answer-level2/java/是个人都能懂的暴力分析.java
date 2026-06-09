
/*
基本思路就是根据当前街道的类型，判断下一步街道类型是否可行。
执行用时 : 6 ms , 在所有 Java 提交中击败了 100.00% 的用户 内存消耗 : 55.5 MB , 在所有 Java 提交中击败了 100.00% 的用户
*/


```

public  static boolean hasValidPath() {
		int[][] grid=new int[][]{{2,4,3},{6,5,2}};
		int n=grid[0].length;
		int m=grid.length;
		boolean ToRight=true;//表示此时是否方向向右
		boolean ToDown=true;//表示此时是否方向向下
		for(int i=0;i<m;)
		{
			for(int j=0;j<n;)
			{
				if(i==m-1&&j==n-1) return true;//如果此时的位置是在右下角终点，则返回true

				if(grid[i][j]==1)//此时的位置的街道为1类型
				{
					if(ToRight)//如果此时的方向是向右走的，则只需要判断右一格能否列接通
						{
						if(j==n-1||(grid[i][j+1]!=1&&grid[i][j+1]!=3&&grid[i][j+1]!=5))//右一格不存在或者不是类型1，3，5则走不通，返回false
							return false;
						if(grid[i][j+1]==3) ToDown=true;//下一格的类型是类型3，则向下方向不变
						if(grid[i][j+1]==5) ToDown=false;//下一格的类型是5，则向下方向改变，变成向上
						j++;//往右走一步
						
						}
					if(!ToRight)//如果此时的方向是向左走的，则只需要判断左一格能否列接通
						{
							if(j==0||(grid[i][j-1]!=1&&grid[i][j-1]!=4&&grid[i][j-1]!=6))//左一格不存在或者不是类型1，4，6则走不通，返回false
							{
								return false;
							}
							if(grid[i][j-1]==4) ToDown=true;//下一格的类型是类型4，则向下方向不变
							if(grid[i][j-1]==6) ToDown=false;//下一格的类型是类型6，则向下方向改变，变成向上
							j--;
						}
					
				}
				//以下依次根据当前街道的类型，判断下一步街道类型是否有效
				else if(grid[i][j]==2)
				{
					if(ToDown)
					{
						if(i==m-1||(grid[i+1][j]!=2&&grid[i+1][j]!=5&&grid[i+1][j]!=6)) return false;
						if(grid[i+1][j]==5) ToRight=false;
						if(grid[i+1][j]==6) ToRight=true;
						i++;
					}
					if(!ToDown)
					{
						if(i==0||(grid[i-1][j]!=2&&grid[i-1][j]!=3&&grid[i-1][j]!=4)) return false;
						if(grid[i-1][j]==3) ToRight=false;
						if(grid[i-1][j]==4) ToRight=true;
						i--;
					}

				}

				else if(grid[i][j]==3)
				{
					if(ToDown)
					{
						if((i==m-1)||grid[i+1][j]!=2&&grid[i+1][j]!=5&&grid[i+1][j]!=6) return false;
						if(grid[i+1][j]==5) ToRight=false;
						if(grid[i+1][j]==6) ToRight=true;
						i++;
					}
					if(!ToDown)
					{
						if(j==0||(grid[i][j-1]!=1&&grid[i][j-1]!=4&&grid[i][j-1]!=6))
						{
							return false;
						}
						if(grid[i][j-1]==4) ToDown=true;
						if(grid[i][j-1]==6) ToDown=false;
						j--;
					}
				}

				else if(grid[i][j]==4)
				{
					if(ToDown)
					{
						if(i==m-1||grid[i+1][j]!=2&&grid[i+1][j]!=5&&grid[i+1][j]!=6) return false;
						if(grid[i+1][j]==5) ToRight=false;
						if(grid[i+1][j]==6) ToRight=true;
						i++;
					}
					if(!ToDown)
					{
						if(j==0||(grid[i][j+1]!=1&&grid[i][j+1]!=3&&grid[i][j+1]!=5))
						{
							return false;
						}
						if(grid[i][j+1]==3) ToDown=true;
						if(grid[i][j+1]==5) ToRight=false;
						j++;
					}
				}
				else if(grid[i][j]==5)
				{
					if(ToDown)
					{
						if(j==0||(grid[i][j-1]!=1&&grid[i][j-1]!=4&&grid[i][j-1]!=6))
						{
							return false;
						}
						if(grid[i][j-1]==4) ToDown=true;
						if(grid[i][j-1]==6) ToDown=false;
						j--;
					}
					if(!ToDown)
					{
						if(i==0||(grid[i-1][j]!=2&&grid[i-1][j]!=3&&grid[i-1][j]!=4)) return false;
						if(grid[i-1][j]==3) ToRight=false;
						if(grid[i-1][j]==4) ToRight=true;
						i--;
					}
				}
				else if(grid[i][j]==6)
				{
					if(ToDown)
					{
						if(j==n-1||(grid[i][j+1]!=1&&grid[i][j+1]!=3&&grid[i][j+1]!=5))
							return false;
						if(grid[i][j+1]==3) ToDown=true;
						if(grid[i][j+1]==5) ToDown=false;
						j++;
					}
					else {
						if(i==0||(grid[i-1][j]!=2&&grid[i-1][j]!=3&&grid[i-1][j]!=4)) return false;
						if(grid[i-1][j]==3) ToRight=false;
						if(grid[i-1][j]==4) ToRight=true;
						i--;
					}
				}
					
			}
		}
		return false;
    }
```
