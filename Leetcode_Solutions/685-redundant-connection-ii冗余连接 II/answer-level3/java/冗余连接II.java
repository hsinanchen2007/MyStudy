# 思路
总体思路与冗余连接类似，不过分两种情况
1. 若所有结点入度均为1，说明存在环路，直接建立并查集就可
2. 若有一个结点入度为2，则有两个结点指向该结点，这两条边优先删除位于临边数组后边的一条边，若不能连通返回另一条，否则返回该条

# 代码
```java []
class Solution {
    public int find_root(int[] rp,int node){
        while(rp[node]!=node) 
            node=rp[node];
        return node;
    }

    public int[] findRedundantDirectedConnection(int[][] edges) {
        int[] degrees=new int[edges.length+1];
        int flag=-1;
        for(int[] edge:edges){
            degrees[edge[1]]+=1;
            if(degrees[edge[1]]==2) {
                flag=edge[1];
                break;
            }
        }
        if(flag==-1){
            int[] rp=new int[edges.length+1];
            int i,j;
            for(i=0;i<edges.length+1;i++) rp[i]=i;
            int r1=0,r0=0;
            for(int[] edge: edges){
                r0=find_root(rp,edge[0]);
                r1=find_root(rp,edge[1]);
                if(r0==r1) return edge;
                else rp[r1]=rp[r0];
            }
            return new int[0];
        }
        else{
            int pre=-1,pre1=-1;
            int[] rp=new int[edges.length+1];
            int i,j,count=0;
            for(i=0;i<edges.length+1;i++) rp[i]=i;
            for(i=0;i<edges.length;i++){
                if(edges[i][1]==flag){
                    if(pre==-1) pre=i;
                    else{pre1=i;break;}
                }
            }
            int r1=0,r0=0;
            for(i=0;i<edges.length;i++){
                if(i==pre1) continue;
                r0=find_root(rp,edges[i][0]);
                r1=find_root(rp,edges[i][1]);
                rp[r1]=rp[r0];
            }
            for(i=1;i<rp.length;i++){
                if(rp[i]==i) count++;
            }
            if(count==2) return edges[pre];
            else return edges[pre1];
        }
    }
}


```
