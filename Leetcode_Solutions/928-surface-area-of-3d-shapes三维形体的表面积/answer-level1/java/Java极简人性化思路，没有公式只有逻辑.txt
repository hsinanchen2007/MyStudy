执行用时 :4 ms, 在所有 Java 提交中击败了74.18%的用户
内存消耗 :41.4 MB, 在所有 Java 提交中击败了88.24%的用户
### 解题思路
ans记录最大表面积，每次查看一个格子的上面up和左边left是否有格子，有格子的话得看左边或者上面和当前格子紧贴在一起的那个面哪个高，取高的减去矮的差的绝对值，因为这有这个差部分才是漏在外面的。而如果左边和上面没格子那么当前格子必定在四周边缘位置，直接加该格子高度即可，因为没有格子能把四周格子的外面一圈遮住。最后因为我们只查看了上面和左边相接处，那么最右边一列格子和最下面一列格子的边缘我们还没查看，所以都得加在ans里面。
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
		int ans = 0 ;
		for(int i=0;i<grid.length;i++) {
			for(int j=0;j<grid[i].length;j++) {
				if(grid[i][j]!=0)
                    ans += 2 ;
				if(j-1<0) { // up 
					ans += grid[i][j] ;
				}else {
					ans += Math.abs(grid[i][j]-grid[i][j-1]) ;
				}
				if(i-1<0) { // left 
					ans += grid[i][j] ;
				}else {
					ans += Math.abs(grid[i][j]-grid[i-1][j]) ;
				}
				if(j==grid[i].length-1)
					ans += grid[i][j] ;
				if(i==grid.length-1)
					ans += grid[i][j] ;
			}
		}
		return ans ;
    }
}
```