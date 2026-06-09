### 解题思路
  我目前的思路是采用回溯法，即为每一条边设为未访问节点，从初始点开始，每次找到所有的未访问可行点，若不可行，则回退
  回退的同时将之前访问过的边设为未访问节点，但是会导致死循环啊，莫法，看解析
  首先这是一个一笔画问题，其中涉及到了欧拉回路，即不重复访问一个边来把一个图中所有边访问一次。
（无向图）欧拉路径存在充要条件（本题无关）：图中每个非起点（终点）的点入度和出度相差0，或者起始点的入度和出度差1，同时终点入度和出度差1，
（无向图）欧拉路径存在充要条件（本题无需证明）：起点入度比出度大1，终点入度比出度小1，其他点入度出度相同。
 Hierholzier算法是通过给每条边建标注，不同于给普通的dfs给点加标注然后一个边一个边删去即可。

### 代码

```java
class Solution {
    
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String,PriorityQueue<String>> map=new HashMap<>();
        for(List<String> ticket:tickets){
            PriorityQueue<String> neighbor=map.computeIfAbsent(ticket.get(0),k->new PriorityQueue<>());
            neighbor.offer(ticket.get(1));
        }
        List<String> result=new LinkedList<>();
        dfs(map,"JFK",result);
        return result;
    }

    public void dfs(Map<String,PriorityQueue<String>> map,String src,List<String> result){
        PriorityQueue<String> queue=map.get(src);
        while(queue!=null&&queue.size()>0){
            String poll=queue.poll();
            dfs(map,poll,result);
        }
        result.add(0,src);
    }
}
```