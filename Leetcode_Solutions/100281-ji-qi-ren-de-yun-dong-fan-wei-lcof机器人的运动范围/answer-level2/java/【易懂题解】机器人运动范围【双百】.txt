### 解题思路
从`(0,0)`开始，进行DFS，向右、向下搜索，（剪枝）无需向右或向上搜索，然后一个个的记录能走的格子。

**多说无益，看代码，注释详尽！**

### 代码

```java
class Solution {
    int hang,lie,zhi;
    public int movingCount(int m, int n, int k) {
        boolean ok[][]=new boolean[m][n];//标记是否访问
        hang=m;//记录行数
        lie=n;//记录列数
        zhi=k;//记录k值
        return dfs(0,0,ok);//从(0,0)开始搜
    }
    public int dfs(int x,int y,boolean ok[][]){
        if(ok[x][y]||x/10+x%10+y/10+y%10>zhi||x==hang||y==lie)//已访问、大于k、越界
            return 0;
        ok[x][y]=true;//标记已被访问
        return dfs(x+1,y,ok)+dfs(x,y+1,ok)+1;//找右边和下面
    }
}
```