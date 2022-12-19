### 解题思路
不怕晚 
### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
 boolean change=false;
		 List<Integer[]> list=new ArrayList<>();
		 int time=0;
		 while(hasFresh(grid)){
			 for(int i=0;i<grid.length;i++){
				 for(int j=0;j<grid[0].length;j++){
					 if(grid[i][j]==2){
						 Integer[] t={i,j};
						 list.add(t);
					 }
				 }
			 }if(!list.isEmpty()){
					 change=letsrot(grid,list);
					 time++;
				 }
			 if(!change&&hasFresh(grid))
				 return -1;
			 else if(!change)
				 continue;
			 change=false;
			 }
		 if(!hasFresh(grid)){
			 return time;//>0?(time-1):0;
		 }
		 else 
			 return -1;
	
		 }
	 
	    

	private boolean letsrot(int[][] grid, List<Integer[]> list) {
		boolean change=false;
		for(int k=0;k<list.size();k++){
			Integer[] temp=list.get(k);
			int i=temp[0];
			int j=temp[1];
		 
			 if(i>0&&grid[i-1][j]==1){
				 change=true;
				 grid[i-1][j]=2;
			 }
			 if(i<grid.length-1&&grid[i+1][j]==1)
			 {
				 change=true;
				 grid[i+1][j]=2;
			 }
			 if(j<grid[0].length-1&&grid[i][j+1]==1){
				 change=true;
				 grid[i][j+1]=2;
			 }
			 if(j>0&&grid[i][j-1]==1){
				 change=true;
				 grid[i][j-1]=2;
			 }
		 
		}
		return change;
	}

	private boolean hasFresh(int[][] grid) {
		 for(int i=0;i<grid.length;i++){
			 for(int j=0;j<grid[0].length;j++){
				 if(grid[i][j]==1){
					 return true;
				 }
			 }
		 }
		 return false;
	}
}
```