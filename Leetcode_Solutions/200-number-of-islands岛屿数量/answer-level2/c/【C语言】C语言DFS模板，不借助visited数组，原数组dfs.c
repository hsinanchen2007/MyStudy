### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/bf6689bac6911f312a6d443470919e558805952df73b2cfedeb03df8cc0bc2a5-image.png)

### 代码

```c
int direc[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}  };  // dfs的路径方向
void dfs(char** grid, int gridSize, int* gridColSize, int i, int j){

	if(grid[i][j]!='1') {  // 访问过直接返回
		return;
	}
	// 未访问过，则访问，但先置位
	grid[i][j] = '2';
	// 作 4 个方向的dfs
	for(int k=0;k<4;k++) {
		int tmpX = i + direc[k][0];
		int tmpY = j + direc[k][1];
		if(tmpX<0 || tmpX>=gridSize|| tmpY<0|| tmpY>=gridColSize[0]) {  // 四个方向改动后边界防护
			continue;   // 这种写法关键是 边界防护 是 continue 而不是 return 
		}
		dfs(grid, gridSize, gridColSize, tmpX, tmpY);
	}
}

// dfs
int numIslands(char** grid, int gridSize, int* gridColSize){
	int count=0;
    if(gridSize==0){
        return 0;
    }
	for(int i=0;i<gridSize;i++) {
		for(int j=0;j<gridColSize[0];j++) {
			if(grid[i][j]=='1'){
				dfs(grid, gridSize, gridColSize, i, j);
                count++;
			}
		}
	}
    return count;

}
```