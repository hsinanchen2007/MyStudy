**思路**：0分钟已腐烂橘子会感染其周围四方向的未腐烂橘子 这些刚被感染的橘子作为新一轮的已腐烂橘子...
**注意**：本人菜鸡 主要的语句都给了注释 还请大家多多指教
```python []
class Solution:
	def orangesRotting(self,grid):
		q=[] #存储这一轮的腐烂的橘子的坐标
		cnt,row,col=0,len(grid),len(grid[0]) #所有的橘子的数量 行数 列数
		for i in range(row):
			for j in range(col):
				t=grid[i][j]
				if t:
					cnt+=1
					if t==2:
						q.append((i,j))
		minutes,cur_cnt=0,len(q) #后一个表示当前一共有多少个腐烂的橘子
		while q and cur_cnt!=cnt:
			new_q=list()
			for i,j in q:
				for r,c in ((i,j-1),(i,j+1),(i-1,j),(i+1,j)): #表示四个方向
					try: #1.捕获AssertionError 2.捕获IndexError <- 都是关于坐标有效性的
						idx=(r,c)
						assert r>=0 and c>=0
						if grid[r][c]==1: #还未腐烂但是在本轮就会腐烂
							new_q.append(idx)
							grid[r][c]=2 #腐烂了
							cur_cnt+=1
					except:
						continue
			q=new_q
			minutes+=1
		return -1 if cnt!=cur_cnt else minutes
```
```golang []
func orangesRotting(grid [][]int) int {
	q:=make([][2]int,0) //当前轮次腐烂的橘子们的坐标
	cnt,row,col:=0,len(grid),len(grid[0]) //所有橘子的数量 行数 列数
	for i,j:=range grid {
		for x,y:=range j {
			if y!=0 {
				cnt++
				if y==2 {
					q=append(q,[2]int{i,x})
				}
			}
		}
	}
	dires:=[4][2]int{[2]int{0,1},[2]int{0,-1},[2]int{1,0},[2]int{-1,0}} //上下左右四个不同的方向
	minutes,cur_cnt:=0,len(q) //后面一个表示目前一共有了多少腐烂的橘子
	for len(q)!=0 && cur_cnt!=cnt {
		new_q:=make([][2]int)
		for _,idx:=range q {
			r,c:=idx[0],idx[1]
			for _,_idx:=range dires {
				_r,_c:=_idx[0],_idx[1]
				if n_r,n_c:=r+_r,c+_c;n_r>=0 && n_r<row && n_c>=0 && n_c<col { //一个坐标可以牵引出上下左右四个不同的新坐标 注意坐标的有效性判断
					if grid[n_r][n_c]==1 { //还未腐烂的橘子
						new_q=append(new_q,[2]int{n_r,n_c})
						grid[n_r][n_c]=2 //表示腐烂
						cur_cnt++
					}
				}
			}
		}
		q=new_q //更新最新腐烂的橘子们
		minutes++
	}
	if cur_cnt==cnt {
		return minutes
	}
	return -1
}
```
