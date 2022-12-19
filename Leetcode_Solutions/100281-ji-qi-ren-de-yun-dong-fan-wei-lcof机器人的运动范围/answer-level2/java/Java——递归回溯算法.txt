结构清晰Java——递归回溯算法
```reasonml
class Solution {

    //count用于在遍历可走格子时进行计数;
    int count=0;
    public int movingCount(int m, int n, int k) {
        //visited数组用于在下/右遍历过程中过滤已访问格子;
        int[][] visited = new int[m][n];
        getCount(0,0,m,n,k,visited);
        return count;
    }

    //仅需向下/右遍历格子
    public void getCount(int i, int j, int m, int n, int k, int[][] visited){
        //数位和大于k,移动到方格外,遍历到已访问格子时直接返回;
        if(getnum(i)+getnum(j)>k||i>=m||j>=n||visited[i][j]==1){
            return;
        }

        count++;
        visited[i][j] = 1;
        //先向下遍历格子,再向右遍历格子;
        getCount(i+1,j,m,n,k,visited);
        getCount(i,j+1,m,n,k,visited);
    }

    //递归求数位和
    public int getnum(int i){
        if(i/10==0){
            return i%10;
        }
        return getnum(i/10) + i%10;
    }
}
```
