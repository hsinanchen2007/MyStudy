查朋友圈，实际上是查图中联通分量个数，使用并查集
并查集的特点，一个集合代表结点的代表结点是其自己，而别的不是
双耗99.5%,96.4%
# 代码
```java []
class Solution {
    public int find(int[] rp, int i){
        while(rp[i]!=i) i=rp[i];
        return i;
    }

    public int findCircleNum(int[][] M) {
        int L=M.length;
        int[] rp=new int [L];
        for(int i=0;i<L;i++){
            rp[i]=i;
        }
        int parent_i=0,parent_j=0;
        for(int i=0;i<L-1;i++){
            for(int j=i+1;j<L;j++){
                if(M[i][j]==1){
                    parent_i=find(rp,i);
                    parent_j=find(rp,j);
                    rp[parent_j]=parent_i;
                }
            }
        }
        int count=0;
        for(int i=0;i<L;i++) if(rp[i]==i) count++;
        return count;
    }
}
```
