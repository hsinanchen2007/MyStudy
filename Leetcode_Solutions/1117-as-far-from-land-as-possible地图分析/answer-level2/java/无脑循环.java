### 解题思路
此处撰写解题思路
在使用了4重循环,简单粗暴
### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
		int re = 0;
		for(int i=0;i<grid.length;i++){
			for(int j=0;j<grid[i].length;j++){
				if(grid[i][j]==0){
					boolean allS = true;
					for(int k=1;k<=(Math.max((grid.length-1-i),i) + Math.max((grid[i].length-1-j),j));k++){
						int le = 0;
						for(int l = 0;l < k;l++){
							if(getValue(i-l,j-(k-l),grid) == 1){
								allS = false;
								le = k;
								break;
							}
							if(getValue(i+l,j+(k-l),grid) == 1){
								allS = false;
								le = k;
								break;
							}
							if(getValue(i-(k-l),j+l,grid) == 1){
								allS = false;
								le = k;
								break;
							}
							if(getValue(i+(k-l),j-l,grid) == 1){
								allS = false;
								le = k;
								break;
							}
						}
						if(le != 0) {
							re = re > le ? re :le;
							break;
						}
						
					}
					if(allS) return -1;
				}
			}
		}
		if(re==0) return -1;
        return re;
    }
    public int getValue(int a,int b,int[][]grid){
		if(a<0 || b<0 || a>=grid.length || b>=grid[0].length){
			return -1;
		}else{
			return grid[a][b];
		}
	}
}
```