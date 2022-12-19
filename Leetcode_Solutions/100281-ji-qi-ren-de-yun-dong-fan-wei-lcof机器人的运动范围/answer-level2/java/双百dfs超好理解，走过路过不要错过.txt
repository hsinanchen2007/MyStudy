dfs的思路大家都知道，本题解是在常规的基础上多一些判断。

1.常规的dfs，一般会沿着上、下、左、右四个方向dfs，但是这题只需要向右、下计算，因为起始点是[0,0]，所以向 右、下计算是能到达任何地方的，这样就省去了很多重复的操作

2.dfs一般都需要额外建一个表来记录哪些已经到达，这题也不例外，生成一个boolean表记录，哪些已经到达，已经到达的地方跳过，如果在dfs中一个地方满足 行坐标和列坐标的数位之和大于k的，那么说明他是可以到达的，继续对他用dfs遍历即可，不满足时，直接跳过，说明不满足。



```
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private int res;
    private boolean[][] marked;
    private int m,n,k;
    public int movingCount(int m, int n, int k) {
        marked=new boolean[m][n];  //记录哪些已经到达
        this.m=m;
        this.n=n;
        this.k=k;
        res=0;
        dfs(0,0);
        return res;
    }

    private void dfs(int i, int j) {
        if(!isArea(i,j)) return; //判断横纵坐标是否在合适的区间类
        if(marked[i][j]) return;  //判断是否已经到达过，达到过返回
        if(isOk(i,j)){   //判断是否满足
            res++;
            dfs(i+1,j);   //继续查找
            dfs(i,j+1);
        }
        marked[i][j]=true;  //表示已经到达过了
    }

    private boolean isArea(int newX, int newY) {
        if(newX<0||newX>=m||newY<0||newY>=n) return false;
        return true;
    }

    private boolean isOk(int newX, int newY){
        return newX%10+newX/10+newY%10+newY/10<=k;
    }

}
```
