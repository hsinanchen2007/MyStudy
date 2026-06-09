### 解题思路
代码真的浅显易懂，注意深拷贝和浅拷贝问题，这里System.arraycopy使用与一维数组是深拷贝，二维数组是浅拷贝
![image.png](https://pic.leetcode-cn.com/571f65172c02ef2f0042f6fbd589bf7093eba24fe59f8a00b86935ddcc95d9be-image.png)



### 代码

```java
class Solution {
    private int lengthX=-1;
	private int lengthY=-1;
	public int[][] gameOfLife(int[][] board) {
        // (<2 death )  (==2 || ==3  live)   (>3  death)  (==3 reviver) 
    	int[][] fx = {{-1,1},{0,1},{1,1},{-1,0},{1,0},{-1,-1},{0,-1},{1,-1}};
    	lengthX=board[0].length;
    	lengthY=board.length;
    	int[][]board2 = new int[lengthY][lengthX];
		for(int i=0;i<board.length;i++) {
			System.arraycopy(board[i],0,board2[i],0,board[0].length);
		}
    	

    	    	    	    	
    	for(int x=0;x<lengthX;x++) {
    		for(int y=0;y<lengthY;y++) {
    			int temp=0;
    			
//    			System.out.println("Node: x:"+x+"   y:"+y);
    			for(int[] nums:fx) {
    				temp+=search(x+nums[0],y+nums[1],board2);
    			}
    			if(temp<2) board[y][x]=0;
    			else if(temp==2) continue;
    			else if(temp>3) board[y][x]=0;
    			else if(temp ==3) board[y][x]=1;
    		}
    	}
    	return board2;
    }
    
    
    
    //查询当前点是否有细胞
    public int search(int x,int y,int[][] board) {
//    	System.out.print("x:"+x+"    y:"+y);
    	if(x>=0 && x<lengthX && y>=0 && y<lengthY) {
//    		System.out.println("    res:"+board[y][x]);
    		return board[y][x];
    	}
//    	System.out.println(" ");
    	return 0;
    }
    
    
}
```