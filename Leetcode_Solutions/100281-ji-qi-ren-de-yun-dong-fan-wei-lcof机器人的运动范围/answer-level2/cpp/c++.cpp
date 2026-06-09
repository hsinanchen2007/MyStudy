### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public: 
    int count=0;
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m,vector<int>(n));
       dfs(0,0,k,m,n,visited);
        return count;
    }
    void dfs(int i,int j,int k,int m,int n,vector<vector<int>> &visited)
    {
        if(i==m||j==n||i<0||j<0) return;
        if(visited[i][j]) return;
        int a=i; 
        int b=j;
        int sum=0;
        while(a)
        {
            sum+=a%10;
            a/=10;
        }
        while(b)
        {
            sum+=b%10;
            b/=10;
        }
        if(sum>k) return;

        visited[i][j] = 1;
         count++;
        dfs(i+1,j,k,m,n,visited);
        dfs(i,j+1,k,m,n,visited);
        dfs(i-1,j,k,m,n,visited);
        dfs(i,j-1,k,m,n,visited);

    }
};
```