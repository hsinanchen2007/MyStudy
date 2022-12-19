```java
class Solution {
 
    //定义结点类，表示员工的id和被通知时的时间
    class Node{
        public int id;
        public int time;
        public Node(int i,int time){
            this.id = i;
            this.time = time;
        }
    }
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int result=0;

        //HashMap索引为员工编号，值为存放下属id的List
        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int i=0;i<n;i++) {
            List<Integer> ls = map.getOrDefault(manager[i],new ArrayList<Integer>());
            ls.add(i);
            map.put(manager[i],ls);
        }

        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(headID,0));
        while(!q.isEmpty()) {
            Node node= q.poll();
            //遍历当前员工的HashMap，将下属的员工加入队列
            for(Integer i:map.getOrDefault(node.id,new ArrayList<>())){
                q.offer(new Node(i,node.time+informTime[node.id]));
            }
            Math.max(node.time,result);
        }
        return result;
    }
}
```
