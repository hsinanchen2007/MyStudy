### 解题思路
这里我们用了BFS广度优先算法，而这道题的解就是当队列中的数全部遍历完的所得的层数，根据队列的属性我们可以有序的来对整个数组进行遍历既按照一定的顺序来，为了不重复遍历，我们可以将遍历完的数组从0改成1.

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int[][] directions ={{1,0},{0,1},{-1,0},{0,-1}};//这里是为了查找当前数组的上右下左
	     int n = grid.length;
	     Queue<int []> queue = new LinkedList<>();
	     for(int i=0;i<n;i++)
	    	 for(int j=0;j<n;j++){
	    		 if(grid[i][j] == 1){
	    			 queue.add(new int[]{i,j});//直接将数组的行列数存入，方便查找
	    		 }
	    	 }
	     int size = queue.size();
	     if(size == 0 || size == n*n){
	    	 return -1;
	     }
	     int floor = 0;
	     while(!queue.isEmpty()){//当队列为空就代表全部遍历完了
	    	 int currentSize = queue.size();//首先进行第一次得到的数为1的个数
	    	 for(int i=0;i<currentSize;i++){//进行多源点查找
	    	 int[] head = queue.poll();//按照加到队列的顺序依次拿出
	    	 
	    	 int headX = head[0];
	    	 int headY = head[1];
	    	 for(int [] direction:directions){//开始查找当前数组的上下左右有没有0
	    		 int newX = headX + direction[0];
	    		 int newY = headY + direction[1];
	    		 if(inAire(newX,newY,n) && grid[newX][newY] == 0){
	    			 grid[newX][newY] = 1;//做记号代表走过
	    			 queue.add(new int[]{newX,newY});
	    		 }
	    	 }
	    	 }
	    	 floor++;
	     }
			//最后一次遍历完之后floor又加了一个1，所以flour-1
	     return floor-1;
	 }

	private boolean inAire(int newX, int newY,int n) {//保证在区域之内
		// TODO Auto-generated method stub
		return 0<=newX && newX<n && 0<=newY && newY<n;
	}

    }

```