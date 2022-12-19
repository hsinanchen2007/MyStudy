### 解题思路
大致思路就是,根据题中问题:可能出现两种情况，一种就是环的存在,另一种就是重复父节点的问题（一个节点有两个父节点）
分步解决:
  先合并有向边,找出可能存在的重复父节点问题
  然后再重新初始化，解决是否存在环的问题
### 代码

```java
class Solution {
    
    private int []parent=null;

    private int find(int u){

        while(u!=parent[u]){
          //压缩路径
          parent[u]=parent[parent[u]];
          u=parent[u];

        }
        return u;
    }

    /**
     *
     * @param edges
     * @return
     * 需要考虑有没有环和重复的父节点
     */
    public int[] findRedundantDirectedConnection(int[][] edges) {

     
        int [] backedge=new int[2];//存放最后一个后向边(环)
        int [] pending=new int[2];//存放最后一个重复的父节点
        parent = new int[edges.length + 1];
       
        for(int []edge:edges){

            if(parent[edge[1]]==0){//合并有向边
                parent[edge[1]]=edge[0];
            }else{//有重复的父节点
                pending=new int[]{edge[0],edge[1]};
                backedge=new int[]{parent[edge[1]],edge[1]};
                edge[1]=0;
            }
        }
        for (int i = 0; i <=edges.length; i++) {
            parent[i] = i;
        }
        
        for(int[]e:edges){

            if(e[1]==0){
                continue;
            }
            //判断有没有环
            if(find(e[0])==e[1]){
               return backedge[0]!=0?backedge:e;
            }
            parent[e[1]]=e[0];
        }

        return pending;
    }
}
```