我的基本思路是去看每个岛能对总周长贡献几条边。例如一个岛四周都没有岛，自然是贡献4条边。如果一个岛周围有一个岛，那么它就只能贡献3条边，以此类推。

因此，其实就是遍历整个矩阵，每遍历到一个岛，则去看这个岛的上下左右有没有岛。可以发现如果一个岛附近每有一个岛，则这个岛贡献的周长会-1。最后返回贡献和即可。

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
      	int sum = 0;
      	for(int i = 0; i < grid.length; i++) {
          	for(int j = 0; j < grid[0].length; j++) {
              	if(grid[i][j] == 1) {
                  	int lines = 4;
                  	//判断这个岛旁边连接了多少个岛
                  	if(i > 0 && grid[i - 1][j] == 1) lines--;
                  	if(i < grid.length - 1 && grid[i + 1][j] == 1) lines--;
                  	if(j > 0 && grid[i][j - 1] == 1) lines--;
                  	if(j < grid[0].length - 1 && grid[i][j + 1] == 1) lines--;
                  	sum += lines;
                }
            }
        }
      	return sum;
    }
}
```