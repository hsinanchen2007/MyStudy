### 解题思路
此处撰写解题思路

### 代码

```golang
func numMagicSquaresInside(grid [][]int) int {
	res:=0
	for i:=0;i< len(grid)-2;i++{
		for j:=0;j< len(grid[0])-2;j++{
			fmt.Println(grid[i][j])
			tmp:=make([][]int,0,3)
			for m:=0;m<3;m++{
				t:=make([]int,0,3)
				for n:=0;n<3;n++{
					t= append(t, grid[i+m][j+n])
				}
				tmp= append(tmp, t)
			}
			fmt.Println(tmp)
			if helpnumMagicSquaresInside(tmp){
				res++
			}
		}
	}
	return res
}
//判断一个3*3矩阵是不是幻方
func helpnumMagicSquaresInside(grid [][]int)bool{
	mapNum:=make(map[int]int)
	for i:=0;i<3;i++{
		for j:=0;j<3;j++{
			if !(grid[i][j]>=1&&grid[i][j]<=9){
				return false
			}else{
				mapNum[grid[i][j]]=1
			}
		}
	}
	if len(mapNum)!=9{
		return false
	}
	if len(grid)!=3|| len(grid[0])!=3{
		return false
	}
	for i:=0;i< len(grid);i++{
		if grid[i][0]+grid[i][1]+grid[i][2]!=15{
			return false
		}
	}
	for j:=0;j<3;j++{
		if grid[0][j]+grid[1][j]+grid[2][j]!=15{
			return false
		}
	}
	if grid[0][0]+grid[1][1]+grid[2][2]!=15||grid[2][0]+grid[1][1]+grid[0][2]!=15{
		return false
	}
	return true
}

```