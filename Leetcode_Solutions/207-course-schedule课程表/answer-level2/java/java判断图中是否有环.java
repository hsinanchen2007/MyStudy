### 解题思路
建立一个图结构+判断是否有环（-1状态代表没有访问，0代表正在访问，1已经访问了）

### 代码

```java
class GraphNode {
    int value;
    List<GraphNode> neighbours = new LinkedList<>();
    GraphNode(int x) {
        this.value = x;
    }
}

class Solution {

    public boolean dfs(int[] visited,GraphNode node) {
        if(visited[node.value] == 1){
            return false;
        }
        if(visited[node.value] == 0){
            return true;
        }
        visited[node.value] = 0;
        for(GraphNode child: node.neighbours) {
            if(dfs(visited,child)) {
                return true;
            }
        }
        visited[node.value] = 1;
        return false;
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        Map<Integer,GraphNode> maps = new HashMap<>();
        for(int i =0;i<numCourses;++i) {
            maps.put(i,new GraphNode(i));
        }

        int[] visited = new int[numCourses];

        for(int i =0;i<numCourses;++i) {
            visited[i] = -1 ;
        }

        for(int[] lists:prerequisites) {
            int start = lists[0];
            int end = lists[1];
            maps.get(start).neighbours.add(maps.get(end));
        }

        for(Integer key: maps.keySet()) {
            GraphNode value = maps.get(key);
            //System.out.println(value.value);
            if(dfs(visited,value)) {
                return false;
            }
            

        }
        return true;
    }
}
```