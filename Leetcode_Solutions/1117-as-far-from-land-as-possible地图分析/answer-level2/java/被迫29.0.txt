if(grid==null) {
    		return -1;
    	}
    	int m = grid.length;
    	int n = grid[0].length;
    	Queue<int[]> queue = new LinkedList<int[]>();
    	for(int i=0;i<m;i++) {
    		for(int j =0;j<n;j++) {
    			if(grid[i][j]==1) {
    				queue.offer(new int[] {i,j});
    			}
    		}
    	}
    	int [] dx = {0,0,-1,1};
    	int [] dy = {-1,1,0,0};
    	int [] ans = null;
    	boolean b = false;
    	while(!queue.isEmpty()) {
    		ans=queue.poll();
    		int x = ans[0];
    		int y = ans[1];
    		for(int i=0;i<4;i++) {
    			int new_x = x+dx[i];
    			int new_y = y+dy[i];
    			if(new_x<0||new_x>=m||new_y<0||new_y>=n||grid[new_x][new_y]!=0) {
    				continue;
    			}
    			grid[new_x][new_y]=grid[x][y]+1;
    			b=true;
    			queue.offer(new int [] {new_x,new_y});
    		}
    	}
    	if(ans==null||!b) {
    		return -1;
    	}
    	return grid[ans[0]][ans[1]]-1;