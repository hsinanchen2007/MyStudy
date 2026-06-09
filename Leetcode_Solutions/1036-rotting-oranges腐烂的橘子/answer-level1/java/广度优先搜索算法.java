### 解题思路
此处撰写解题思路
很显然的广度优先搜索算法，可以说的就是集合的存储（x,y）用x*列数+y=z ,z是唯一，并且可以逆运算得到x，y
上下左右方向用一个数组存起来，然后循环loop的技巧。
类似的题目还有岛屿问题。
### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
    	//规定四个方向
    	int[][] dir= {{0,-1},{0,1},{1,0},{-1,0}};
    	Queue<Integer> queue=new LinkedList<Integer>();
    	HashSet<Integer> set=new HashSet<Integer>();
    	//1.扫描未腐烂的橘子->加入set
    	//1.扫描腐烂的橘子->加入queue
    	for(int i=0;i<grid.length;i++) {
    		for(int j=0;j<grid[i].length;j++) {
    			if(grid[i][j]==1) {
    				//如果为未腐烂的橘子
    				set.add(i*grid[0].length+j);
    			}
    			else if(grid[i][j]==2) {
    				queue.add(i*grid[0].length+j);
    			}
    		}
    	}
    	//System.out.printf("[%d %d]",grid.length,grid[0].length);
    	//开始腐烂把
    	int loopTime=0;
    	while(!queue.isEmpty()) {
    		if(set.isEmpty()) {
    			break;
    		}
    		int sizes=queue.size();
    		//第一轮迭代的队列长度sizes
    		for(int i=0;i<sizes;i++) {
    			//向四个方向腐烂
    			int point=queue.poll();
    			int x=point/grid[0].length;
    			int y=point%grid[0].length;
    			//System.out.printf("(%d,%d)\n", x,y);
    			for(int k=0;k<dir.length;k++) {
    				int tarX=x+dir[k][0];
    				int tarY=y+dir[k][1];
    				//System.out.printf("(%d,%d)\n", tarX,tarY);
    				if(tarX<0||tarY<0||tarX>=grid.length||
    						tarY>=grid[0].length) {
    					//System.out.print("out bound");
    				}//if-end
    				else if(grid[tarX][tarY]==1) {
    					//腐烂它！烂橘子
    					//1.新鲜的橘子被腐烂了
    					Integer orange=tarX*grid[0].length+tarY;
    					set.remove(orange);
    					//腐烂橘子来了
    					grid[tarX][tarY]=2;
    					queue.add(orange);
    				}//else-if -end
    				
    			}//for-loop-four dir
    			
    		}//for-loop-oneloop
    		//一轮腐烂结束
    		loopTime++;
    	}//while-loop
    	if(set.isEmpty()) {
    		return loopTime;
    	}
    	else {
    		return -1;
    	}
    }
}

```