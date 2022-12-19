### 解题思路
参考官方题解动态规划法

### 代码

```golang
func maxDistance(grid [][]int) int {
	if len(grid)==0||len(grid[0])==0{
		return -1
	}
	res:=make([][]int,0)
	for i:=0;i<len(grid);i++{
		temp:=make([]int,len(grid[0]))
		res=append(res,temp)
	}
	for i:=0;i<len(grid);i++{
		for j:=0;j<len(grid[0]);j++{
			if grid[i][j]==0{
				if i==0&&j==0{
					res[i][j]=math.MaxInt32
				}else if i==0{
					res[i][j]=res[i][j-1]+1
				}else if j==0{
					res[i][j]=res[i-1][j]+1
				}else {
					res[i][j]=min(res[i-1][j],res[i][j-1])+1
				}
			}else{
				res[i][j]=0
			}
		}
	}
	for i:=len(grid)-1;i>=0;i--{
		for j:=len(grid[0])-1;j>=0;j--{
			if grid[i][j]==0{
				if i==len(grid)-1&&j==len(grid[0])-1{
					res[i][j]=min(res[i][j],math.MaxInt32)
				}else if i==len(grid)-1{
					res[i][j]=min(res[i][j],res[i][j+1]+1)
				}else if j==len(grid[0])-1{
					res[i][j]=min(res[i][j],res[i+1][j]+1)
				}else {
					res[i][j]=min(res[i][j],min(res[i+1][j],res[i][j+1])+1)
				}
			}else{
				res[i][j]=0
			}
		}
	}
	tempMax:=0
	for i:=0;i<len(res);i++{
		for j:=0;j<len(res[0]);j++{
			if res[i][j]>tempMax{
				tempMax=res[i][j]
			}
		}
	}
	if tempMax==0||tempMax>math.MaxInt32{
		return -1
	}
	return tempMax
}

func min(a,b int) int{
    if a<b{
        return a
    }
    return b
}
```