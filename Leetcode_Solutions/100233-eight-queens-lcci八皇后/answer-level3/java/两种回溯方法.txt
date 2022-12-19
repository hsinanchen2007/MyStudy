### 解题思路
方法二用一个二维数组保存不能被占用的格子,效率更高

### 代码

```java
class Solution {
    // 方法1:
    // ArrayList<List<String>> res=new ArrayList();
    //   public List<List<String>> solveNQueens(int n) {
    //     int[] c=new int[n];
    //     helper(0,n,c);
    //     return res;
    // }
    // public void helper(int curr, int n, int[] c){
    //     if(curr==n){
    //         List<String> list=new ArrayList(n);
    //         //c数组记录的是符合题意的皇后该行的列的下标,
    //         for(int i=0;i<n;i++){
    //             StringBuilder row = new StringBuilder();
    //             for(int j=0;j<n;j++){
    //                 if(j==c[i]) row.append('Q');
    //                 else row.append('.');
    //             }
    //             list.add(row.toString());
    //         }
    //         res.add(list);return;
    //     }
    //     else for(int i=0;i<n;i++){
    //         boolean a=true;
    //         c[curr]=i;
    //         for(int j=0;j<curr;j++){
    //             if(c[j]==c[curr]||curr-c[curr]==j-c[j]||curr+c[curr]==j+c[j])
    //             {a=false;break;}
    //         }
    //         if(a) helper(curr+1,n,c);
    //     }
    // }


    //方法2:]
    List<List<String>> res=new ArrayList();
    public List<List<String>> solveNQueens(int n) {
        int[][] vis=new int[3][2*n];
        int[] c=new int[n];
        helper(0,n,vis,c);
        return res;
    }
    public void helper(int curr,int n,int[][] vis,int[]c){
        if(curr==n){
            List<String> list=new ArrayList();
            for(int i=0;i<n;i++){
                StringBuilder sb=new StringBuilder();
                for(int j=0;j<n;j++){
                    if(j==c[i]){
                        sb.append("Q");
                    }
                    else sb.append(".");
                }
                list.add(sb.toString());
            }
            res.add(list);
        }
        else for(int i=0;i<n;i++){
            if(vis[0][i]==0&&vis[1][curr+i]==0&&vis[2][curr-i+n]==0){
                c[curr]=i;
                vis[0][i]=1;vis[1][curr+i]=1;vis[2][curr-i+n]=1;
                helper(curr+1,n,vis,c);
                //注意:回溯,恢复之前状态
                vis[0][i]=0;vis[1][curr+i]=0;vis[2][curr-i+n]=0;
            }
        }
    }
}
```