### 解题思路
![Snipaste_2020-03-12_15-45-56.png](https://pic.leetcode-cn.com/2a91dde9b82039f16804c8652327d42b966cd3f7c396875a26f4c4de31a6db4b-Snipaste_2020-03-12_15-45-56.png)
暴力法竟然双百。。。奇幻！

### 代码

```c
bool isValid(int ** grid,int xstart,int ystart){
    int x,y;
    int i;
    int hash[16]={0};
	const int arr[9][2]={
		{0,0},{0,1},{0,2},
		{1,0},{1,1},{1,2},
		{2,0},{2,1},{2,2},
	};
    for(i=0;i<9;i++){
        x=xstart+arr[i][0];
		y=ystart+arr[i][1];
		if(grid[x][y]<1||grid[x][y]>9){
			return false;
		}
		hash[grid[x][y]]++;
		if(hash[grid[x][y]]>1){
			return false;
		}
    }
    return true;
}
int isMagic(int** grid,int xstart,int ystart){
    int sum,expectsum;
    const int arr[7][3][2] = {
		//{{0, 0}, {0, 1}, {0, 2}},
		{{1,0},{1,1},{1,2}},
		{{2,0},{2,1},{2,2}},
		{{0,0},{1,0},{2,0}},
		{{0,1},{1,1},{2,1}},
		{{0,2},{1,2},{2,2}},
		{{0,0},{1,1},{2,2}},
		{{2,0},{1,1},{0,2}},
	};
    int i,j,k;
    expectsum=grid[xstart][ystart]+grid[xstart][ystart+1] + grid[xstart][ystart+2];
    for(i=0;i<7;i++){
        sum=0;
        for(j=0;j<3;j++){
			sum+=grid[xstart+arr[i][j][0]][ystart+arr[i][j][1]];
		}
		if(sum!=expectsum){
			return 0;
		}
    }
    return 1;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize){
    int i, j;
	int cnt = 0;
	if (gridSize < 3 || gridColSize[0] < 3) {
		return 0;
	}
	for (i = 0; i <= gridSize - 3; i++) {
		for (j = 0; j <= gridColSize[i] - 3; j++) {
			if (isValid(grid, i, j) == true) {
				cnt += isMagic(grid, i, j);
			}
		}
	}
	return cnt;

}
```