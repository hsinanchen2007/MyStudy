### 解题思路

### 代码

```java
class Solution {
    //统计到达的数量
    int counts=0;
    public int movingCount(int m, int n, int k) {
        //辅助数组 用来标记是否统计过
        int[][] visited = new int[m][n];
        //从 0,0位置开始统计
        helper(visited,0,0,m-1,n-1,k);
        return counts;
    }

    /**
    *传入i,j两点 判断当前点是否符合规则 符合规则下继续对下右两个方向递归判断
    */
    private void helper(int[][] visited,int i,int j,int m,int n,int k){
        if(i<=m&&j<=n&&visited[i][j]!=1&&(indexSum(i)+indexSum(j))<=k){
            counts++;
            visited[i][j]=1;
            helper(visited,i+1,j,m,n,k);
            helper(visited,i,j+1,m,n,k);
        }
    }

    // 求出累加和
    private int indexSum(int index){
        if(index / 10 == 0){
            return index % 10;
        }
        return indexSum(index / 10) + index % 10;
    }
}
```