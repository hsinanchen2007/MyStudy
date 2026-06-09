### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //思路：
    //能够攻击K的最多只有8个，四个方向各两个
    //只需要从K往四个方向遍历，遇到的第一个Q就加入答案
    int[] dr={0,0,1,1,1,-1,-1,-1};
    int[] dc={1,-1,0,-1,1,0,-1,1};
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        int[][] help=new int[8][8];
        for(int i=0;i<queens.length;i++){
            help[queens[i][0]][queens[i][1]]=1;
        }
        List<List<Integer>> ans=new ArrayList();
        for(int i=0;i<8;i++){
            findQ(help,king[0],king[1],i,ans);
        }
        return ans;
    }

    public void findQ(int[][] help, int x, int y,int d,List<List<Integer>> ans){
        int r=x+dr[d],c=y+dc[d];
        if(r<0||r>=8||c<0||c>=8) return;
        if( help[r][c]==1){
            ans.add(Arrays.asList(r,c));
            return;
        }
        findQ(help,r,c,d,ans);
    }
}
```