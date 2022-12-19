### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numEnclaves(int[][] A) {
    //岛屿问题的变式题，DFS,从4个边界向中间寻找
    int res=0, m=A.length, n=A[0].length;
    for(int i=0;i<m;i++)
    {
        if(A[i][0]==1)   dfs(A,i,0);
        if(A[i][n-1]==1) dfs(A,i,n-1);
    }

    for(int i=0;i<n;i++)
    {
        if(A[0][i]==1)    dfs(A,0,i);
        if(A[m-1][i]==1)  dfs(A,m-1,i);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==1)
                res+=dfs(A,i,j);
        }
    }
    return res;
    }

    private int dfs(int [][] A,int i,int j)
    {
        if(i<0||i>=A.length||j<0||j>=A[0].length||A[i][j]==0){
            return 0;
        }
        A[i][j]=0;
        return 1+dfs(A,i+1,j)+dfs(A,i-1,j)+dfs(A,i,j+1)+dfs(A,i,j-1);
    }
}
```