### 解题思路
非常简单的一道题，只需要BFS找到矛盾点
第一次提交错误问题在于没有去判断是否是连通图，题目可能出现多个非连通图，所以要遍历每个点

### 代码

```java
class Solution {
    public boolean isBipartite(int[][] graph) {
        int [] nodeType=new int [graph.length];
        Queue<Integer> queue=new LinkedList<>();

        for(int x=0;x<graph.length;x++){
            if(graph[x].length>0&&nodeType[x]==0){
                queue.add(x);
                nodeType[x]=1;
                while(!queue.isEmpty()){
                    int poll=queue.poll();
                    int setNum=1;
                    if(nodeType[poll]==1){
                        setNum=2;
                    }
                    for(int i=0;i<graph[poll].length;i++){
                        if(nodeType[graph[poll][i]]==0){
                            nodeType[graph[poll][i]]=setNum;
                            queue.offer(graph[poll][i]);
                        } else if(nodeType[graph[poll][i]]==1&&setNum==2){
                            return false;
                        } else if(nodeType[graph[poll][i]]==2&&setNum==1){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
}
```