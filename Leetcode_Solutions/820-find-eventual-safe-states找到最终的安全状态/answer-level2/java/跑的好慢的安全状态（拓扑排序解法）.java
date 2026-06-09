### 解题思路
 这道题与课程表很像，都是求解有向无环图，区别在于一个是每轮将入度为0的点剪枝，这里是将出度为0的点剪枝，
 反向邻接表
 第一轮超时。所以考虑减少遍历对象，第二轮将将过，不知道咋这么慢。。。

### 代码

```java
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        // 这道题与课程表很像，都是求解有向无环图，区别在于一个是每轮将入度为0的点剪枝，这里是将出度为0的点剪枝，
        // 反向邻接表
        // 超时。所以考虑减少遍历对象
        Map<Integer,List<Integer>> map=new HashMap<>();
        // 存储出度
        int[] outMap=new int[graph.length];
        // 初始化图
        for(int i=0;i<graph.length;i++){
            outMap[i]=graph[i].length;
            for(int j=0;j<graph[i].length;j++){
                List<Integer> neighbor=map.computeIfAbsent(graph[i][j],k->new ArrayList<>());
                neighbor.add(i);
            }
        }
        // 每轮循环将出度为0的点存到queue
        PriorityQueue<Integer> queue=new PriorityQueue<>();
        // 第一轮用数组找，第二轮用队列找
        Queue<Integer> q=new LinkedList<>();
        for(int i=0;i<outMap.length;i++){
            if(!queue.contains(i)&&outMap[i]==0){
                q.offer(i);
            }
        }
       while(!q.isEmpty()){
           int poll=q.poll();
           queue.add(poll);
           List<Integer> neighbor=map.get(poll);
           if(neighbor==null||neighbor.size()==0){
               continue;
           }
           for(Integer neigh:neighbor){
               outMap[neigh]--;
               if(outMap[neigh]==0){
                   q.offer(neigh);
               }
           }
       }
       List<Integer> result=new ArrayList<>();
       while(!queue.isEmpty()){
           result.add(queue.poll());
       }
       return result;

    }
}
```