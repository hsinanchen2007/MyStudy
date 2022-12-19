```
class Solution {
   	int[][] land;
	 public int[] pondSizes(int[][] land) {
                this.land=land;List<Integer> list=new ArrayList<Integer>();
              for (int i = 0; i < land.length; i++) {
				for (int j = 0; j < land[i].length; j++) {
					int a=dfs(i, j);
					if(a>0) {list.add(a);}
				}
			}
             
             Integer[] res= list.toArray(new Integer[list.size()]);
             Arrays.sort(res);
             int[] ress=new int[res.length];
             for (int i = 0; i < ress.length; i++) {
				ress[i]=res[i];
			}
             return ress;
              
	    }
	 public int dfs(int x,int y) {
		 if(x<0||y<0||x>=land.length||y>=land[x].length||land[x][y]!=0) {return 0;}
		 land[x][y]=1;
		 int up=dfs(x-1, y);
		 int down=dfs(x+1, y);
		 int left=dfs(x, y-1);
		 int right=dfs(x, y+1);
		 int leftup=dfs(x-1, y-1);
		 int leftdown=dfs(x+1, y-1);
		 int rightup=dfs(x-1, y+1);
		 int rightdown=dfs(x+1, y+1);
		 return up+down+left+right+leftup+leftdown+rightup+rightdown+1;
	 }
}
```
