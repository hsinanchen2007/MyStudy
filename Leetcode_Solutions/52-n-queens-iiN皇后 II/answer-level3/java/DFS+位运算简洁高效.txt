![1.png](https://pic.leetcode-cn.com/0d284609e847596a29ab27f11936a92c0c0aa266eff380c0b3d55aa440ed46aa-1.png)

 在为N的棋盘中，定义皇后的攻击范围，DFS层层向下遍历，定义列，撇，捺记录皇后的攻击范围,总共有N的平方个方格，数字0到N的平方-1 可以表示所有格子的状态   

    private int count = 0;
	public int totalNQueens(int n) {
	  DFS(0,0,0,0,n);
	  return count;
	}

	public void DFS(int row,int col,int pie,int na,int n){
	  if(row>=n) {
	    count++;
	    return;
	  }
	  int bits = (~(col | na | pie)) & ((1 << n) - 1); // 获得所有可以摆放皇后的位置
	  while (bits>0){
	    int lowBit = bits & (-bits); 
	    DFS(row+1,col|lowBit,(pie|lowBit)<<1,(na|lowBit)>>1,n);
	    bits = bits&(bits-1); 
	  }
	}