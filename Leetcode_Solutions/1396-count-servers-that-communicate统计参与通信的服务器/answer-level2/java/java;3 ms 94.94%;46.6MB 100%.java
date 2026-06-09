### 解题思路
此处撰写解题思路
### 代码

```java
class Solution {
    public int countServers(int[][] grid) {
        int[] a=new int[grid.length];//记录每行的服务器数量
        int[] b=new int[grid[0].length];//记录每一列的服务器数量
        int ans=0;
        for(int i=0;i<a.length;i++){
            a[i]=0;
            for(int j=0;j<b.length;j++){
                a[i]+=grid[i][j];
                ans+=grid[i][j];//顺便统计好机器总数
            }
        }
        for(int i=0;i<b.length;i++){
            b[i]=0;
            for(int j=0;j<a.length;j++){
                b[i]+=grid[j][i];
            }
        }
        for(int i=0;i<a.length;i++){
            for(int j=0;j<b.length;j++)
            if(a[i]==1&&b[j]==1&&grid[i][j]==1)ans--;//如果机器所在的行和列和都为1就减一
        }
        return ans;
    }
}
```