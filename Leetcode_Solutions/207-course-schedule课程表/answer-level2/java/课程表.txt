像修课程这种具有依赖关系的图，优先考虑拓扑排序
# 建立邻接表和入度数组
建立一个邻接表，把依赖于该结点的结点挂到该结点的邻接链表上
统计一个入度数组，把各结点的入度统计在内
# 初始化
构造一个队列，并把入度为0的结点挂到队列里
# 迭代
在队列不为空时，不断弹出结点，删除该结点出去的边，也就是将依赖于该结点的结点入度减1。若出现一些结点入度降成0，挂到队列末尾。
若该图无环，一定能够遍历完所有节点。若有环，则不会。

# 代码
```java []
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
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
        while(Q.isEmpty()==false){
            node=Q.poll();
            numCourses--;
            for(Integer ii: adjacent.get(node)){
                degrees[ii]-=1;
                if(degrees[ii]==0) Q.offer(ii);
            }
        }
        return numCourses==0;
    }
}
```
