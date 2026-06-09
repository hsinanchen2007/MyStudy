### 解题思路
4ms
二维记录，把三维的障碍数直接用二维数组int[][]来记录，同一位置只保存最小值，因为实际上每个位置的记录障碍数在同一路径长度下只会使用一次，因此只需要保存障碍数最小值，同一位置后续出现大于等于该障碍数的路径一律丢弃。这样能减少三维数组下一定会遍历记录出现的0~k障碍数的情况，当前方法只会遍历出同一位置现kn,k(n-1),...,k2,k1(kn为第n次出现,且小于k(n-1)的障碍数,0<=kn<=k);  剩下的和其他的差不多，BFS就行了,其他语法问题，就不要纠结了，写的比较sb。。。 
### 代码

```java
class Solution {
    public int shortestPath(int[][] grid, int k) {
        int colunm = grid.length;
        int raw = grid[0].length;
        int[][] minBlock = new int[colunm][raw];
        for(int[] ints : minBlock){
            Arrays.fill(ints,-1);
        }
        List<int[]> nextQuery = new ArrayList<>();
        nextQuery.add(new int[]{0,0});
        int step = 0;
        while(!nextQuery.isEmpty()) {
            step++;
            List<int[]> newQuery = new ArrayList<>();
            for(int[] ints : nextQuery){
                if(BFSSearch(ints[0], ints[1], colunm, raw, minBlock ,k,newQuery,grid)){
                    return step-1;
                }
            }
            nextQuery = newQuery;
        }
        return -1;
    }

    private boolean BFSSearch(int m, int n, int colunm, int raw, int[][] minBlock, int k, List<int[]> newQuery, int[][] grid) {
        if(m==colunm-1&&n==raw-1){
            return true;
        }
        if(minBlock[m][n]==-1){
            minBlock[m][n] = 0;
        }
        if(m>0&&minBlock[m][n]+grid[m-1][n]<=k){
            if(minBlock[m][n]+grid[m-1][n]<minBlock[m-1][n]||minBlock[m-1][n]==-1){
                minBlock[m-1][n] = minBlock[m][n]+grid[m-1][n];
                newQuery.add(new int[]{m-1,n});
            }
        }
        if(m<colunm-1&&minBlock[m][n]+grid[m+1][n]<=k){
            if(minBlock[m][n]+grid[m+1][n]<minBlock[m+1][n]||minBlock[m+1][n]==-1){
                minBlock[m+1][n] = minBlock[m][n]+grid[m+1][n];
                newQuery.add(new int[]{m+1,n});
            }
        }
        if(n>0&&minBlock[m][n]+grid[m][n-1]<=k){
            if(minBlock[m][n]+grid[m][n-1]<minBlock[m][n-1]||minBlock[m][n-1]==-1){
                minBlock[m][n-1] = minBlock[m][n]+grid[m][n-1];
                newQuery.add(new int[]{m,n-1});
            }
        }
        if(n<raw-1&&minBlock[m][n]+grid[m][n+1]<=k){
            if(minBlock[m][n]+grid[m][n+1]<minBlock[m][n+1]||minBlock[m][n+1]==-1){
                minBlock[m][n+1] = minBlock[m][n]+grid[m][n+1];
                newQuery.add(new int[]{m,n+1});
            }
        }
        return false;
    }
}
```