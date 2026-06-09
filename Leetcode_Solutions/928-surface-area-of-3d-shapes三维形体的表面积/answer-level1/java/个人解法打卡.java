### 解题思路
遍历数组[i,j]。然后对每一组i，j执行：
1.计算柱子的面数
2.减去与i+1，j号柱子的重复面。（x2是因为后面算i+1，j号柱子时不考虑与前面柱子的重复面）
3.减去与i,j+1号柱子的重复面。
4.前两步都要包括对是否是边界的判断，如果是i的边界则不执行步骤2，如果是j的边界则不执行3，如果都满足则都不执行。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int face = 0;
		for(int i = 0; i < grid.length ; i++) {
			for(int j = 0; j < grid[i].length ; j++) {
				//先计算高度
				int flag = grid[i][j] == 0 ? 0 : 1;
				face += grid[i][j] * 4 +2 * flag;
				//System.out.println( face);
				//减去侧面
//				System.out.println("grid["+i+"].length="+ grid[i].length);
//				System.out.println("grid.length="+ grid.length);
				//System.out.println("i="+ i +", j="+ j);
				if( j == grid[i].length - 1 && i == grid.length - 1) break;
				if( j == grid[i].length - 1) {
					face = face - Math.min(grid[i][j], grid[i+1][j]) * 2;	
					//System.out.println( face);
					//System.out.println("=========j==");				
					continue;
				}
				if( i == grid.length - 1) {
					face = face - Math.min(grid[i][j], grid[i][j+1]) * 2;
					//System.out.println( face);
					//System.out.println("=========i==");
					continue;
				}
				face = face - Math.min(grid[i][j], grid[i][j+1]) * 2;
				face = face - Math.min(grid[i][j], grid[i+1][j]) * 2;
				//System.out.println( face);
				//System.out.println("===========");
			}

			//System.out.println("xxxxxxxxxxxxxxx");
		}
		return face;
    }
}
```