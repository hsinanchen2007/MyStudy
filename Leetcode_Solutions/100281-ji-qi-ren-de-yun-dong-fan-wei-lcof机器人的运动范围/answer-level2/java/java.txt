### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
 int m1, n1, k1;
    boolean[][] visited;
    public int movingCount(int m, int n, int k) {
m1 = m; n1 =n; k1 = k;
visited = new boolean[m][n];
return dfs(0,0);

    }

private int dfs(int x,int y)
{
  if(x>=m1 || y>= n1 ||sums(x)+sums(y)>k1 || visited[x][y] == true)
  {
      return 0;
  }
visited[x][y] = true;

 return 1 + dfs(x + 1, y) + dfs(x, y + 1);

}

    private int sums(int x)
    {
        int ans = 0;
while(x!=0)
{
ans += x%10;
x = x/10;
}
   return ans;
    }

}
```