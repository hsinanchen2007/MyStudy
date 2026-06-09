### 解题思路
这次技巧性比较少了
遍历遍历~~
![image.png](https://pic.leetcode-cn.com/cca74e064134df015f5506969c0c6df5810d8936bcaf21ab56e3f1226cd0f5d2-image.png)

### 代码

```java
class Solution {
	int[][] grid;
    public int largest1BorderedSquare(int[][] grid) {
    	this.grid = grid;
    	int res = 0;
        for(int i=0 ; i<grid.length ; i++) 
        	for(int j=0 ; j<grid[0].length ; j++) 
        		if(grid[i][j]!=0)  res = Math.max(res, helper(i,j));
        return res;
    }
    
    int helper(int x,int y) {
    	int len=1;
    	while(y+len<grid[0].length &&x+len<grid.length&& grid[x][y+len]==1 && grid[x+len][y]==1) {
    		len++;
    	}//先找到上边和左边最大的值
    	while(len>1) {
    		boolean flag = true;
    		for(int i=1 ; i<len ; i++) {
    			if(grid[x+len-1][y+i]!=1 || grid[x+i][y+len-1]!=1) { //依次判断即可
    				flag = false;
    				break;
    			}
    		}
    		if(flag)return len*len;
    		len--;
    	}
    	return 1;
  
    }
}
```