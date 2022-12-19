### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    
    List<List<String>> res;
    boolean[][] vis;
    public List<List<String>> solveNQueens(int n) {
        res = new ArrayList<>();
        vis = new boolean[3][n*2];
        int[] table = new int[n];
        search(table,0,n);
        return res;
    }

    public void search(int[] table,int cur,int n){
        if(cur==n){
            buildres(table,n);
        }else{
            for(int i=0;i<n;i++){
                // 利用visit数组记录同列，左斜线，右斜线是否有棋子
                if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n]){
                    table[cur] = i;
                    vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = true;
                    search(table,cur+1,n);
                    vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = false;
                }
            }
        }
    }
    
    
    // 收集结果
    public void buildres(int[] table,int n){
        List<String> list = new ArrayList<>();
        for(int i=0;i<n;i++){
            StringBuilder sb = new StringBuilder();
            for(int j=0;j<n;j++){
                if(j==table[i]){
                    sb.append("Q");
                }else{
                    sb.append(".");
                }
            }
            list.add(sb.toString());
        }
        res.add(list);
    }
}
```