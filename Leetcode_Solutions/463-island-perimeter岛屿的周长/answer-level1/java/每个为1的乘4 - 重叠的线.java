每个为1的有四条边;再加上上下左右判断是否还存在为1的点，这些事重叠的线需要减掉
执行用时 :9 ms, 在所有 java 提交中击败了89.76%的用户
内存消耗 :58.9 MB, 在所有 java 提交中击败了94.78%的用户

public int islandPerimeter(int[][] grid) {
        int total = 0;
        int repeat = 0;
        for ( int i = 0; i < grid.length; i ++ ) {
        	for ( int j = 0; j < grid[i].length; j ++ ) {
        		if ( grid[i][j] == 1 ) {
        			total ++;
        			
        			if ( i - 1 >= 0 ) {
            			if( grid[i - 1][j] == 1 ) {
            				repeat ++;
            			}
            		}
            		
            		if ( i + 1 < grid.length ) {
            			if( grid[i + 1][j] == 1 ) {
            				repeat ++;
            			}
            		}
            		
            		if ( j - 1 >= 0 ) {
            			if( grid[i][j - 1] == 1 ) {
            				repeat ++;
            			}
            		}
            		
            		if ( j + 1 < grid[i].length ) {
            			if( grid[i][j + 1] == 1 ) {
            				repeat ++;
            			}
            		}
        		}
        	}
        }
        
        return total * 4 - repeat;
    }