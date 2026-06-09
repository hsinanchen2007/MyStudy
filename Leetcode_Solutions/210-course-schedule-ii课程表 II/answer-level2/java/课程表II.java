仍然是利用广度优先遍历进行拓扑排序，不过是把遍历过程存了下来
```java []
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int res[] = new int[numCourses];
        int node;
        List<List<Integer>> adjacent = new LinkedList();
        Deque<Integer> Q=new LinkedList();
        for(int i=0;i<numCourses;i++) adjacent.add(new LinkedList());
        int[] degrees=new int[numCourses];
        for(int[] cp: prerequisites){
            degrees[cp[0]]++;     //统计入度
            adjacent.get(cp[1]).add(cp[0]);    //构造邻接表
        }
        for(int i=0;i<degrees.length;i++){
            if(degrees[i]==0){
                Q.offer(i);
            }
        }
        int index=0;
        while(Q.isEmpty()==false){
            node=Q.poll();
            res[index++]=node;
            for(Integer ii: adjacent.get(node)){
                degrees[ii]-=1;
                if(degrees[ii]==0) Q.offer(ii);
            }
        }
        if(index==numCourses) return res;
        else return new int[0];
    }
}
```
