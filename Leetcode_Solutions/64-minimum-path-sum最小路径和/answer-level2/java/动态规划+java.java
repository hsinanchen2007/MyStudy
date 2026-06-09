解题思路：动态规划，从第一行开始，一行一行地求出到达行内每一个位置所需要的最小路径和。
由于到达一个位置只可能从上方或者从左方，故对矩阵中间某一个特定的位置，比较 其上方元素的最小路径和+该元素 与 其左方元素的最小路径和+该元素 的大小，将那个小的作为该元素的最小路径和。对于第一行/第一列，作特殊情况处理。
具体算法：
1、设置一个n维大小的temp数组；
2、行循环，对第一行，temp的第一个数为行的第一个数，后面每一个数为temp的前一个数+第一行的这个数；
3、对剩余的所有行，temp的第一个数为目前的temp第一个数加上该行的第一个数，后面每一个数为 min(temp的前一个数+该行的这个数,temp的这个数+该行的这个数) 这就是上面说的比较从上面走和从左面走的路径大小，将小的作为这个元素的路径长度；
4、循环完成，返回temp的最后一个数，也就是最后一行最后一个位置的最短路径和。
代码如下：
```
public int minPathSum(int[][] grid) {
		int res = 0;
		if(grid.length == 0) {
			return res;
		}
		int m = grid.length;
        int n = grid[0].length;
        int[] temp = new int[n];
        Arrays.fill(temp, 0);
        for(int i = 0; i<m; i++) {
        	int[] row = grid[i];
        	for(int j = 0; j<n; j++) {
        		if(i == 0) {
        			if(j != 0)
        				temp[j] = temp[j-1] + row[j];
        			else
        				temp[j] = row[j];
        		}
        		else{
        			if(j == 0) {
            			temp[j] += row[j];
            		}
            		else {
            			temp[j] = (temp[j]<temp[j-1] ? temp[j]+row[j]:temp[j-1]+row[j]);
            		}
        		}
        	}
        }
        res = temp[n-1];
        return res;
    }
```
