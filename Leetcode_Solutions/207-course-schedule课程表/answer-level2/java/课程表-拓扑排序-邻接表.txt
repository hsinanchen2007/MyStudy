### 解题思路
1. 看这个题没有思路，涉及到图的知识盲区。。
2. 拓扑排序思路比较容易理解，就是要依次的去掉入度为0的顶点，直到去掉所有的顶点，如果有顶点入度不为0，那么说明图中有环路。
3. 这个题关键是如果获得邻接表，如何保存入度列表，这不仅需要熟悉拓扑算法，还需要熟悉一些数据结构，哈希集合，队列等。
4. 本题中有Set[]集合数组，这个用做邻接表。for(int[] p : prerequisites)及foreach二维数组的用法。学到了。

### 代码

```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int preLen = prerequisites.length;
        int[] indegree = new int[numCourses];

        Set<Integer>[] set = new HashSet[numCourses];
        for(int i = 0; i < numCourses; i++)
            set[i] = new HashSet<>();
        
        for(int[] p : prerequisites){
            indegree[p[0]]++;
            set[p[1]].add(p[0]);
        }

        Queue<Integer> queue = new LinkedList<>();
        int count = 0;
        for(int i = 0; i < indegree.length; i++)
            if(indegree[i] == 0)
                queue.add(i);

        while(!queue.isEmpty()){
            int i = queue.poll();
            count++;
            for(int j : set[i]){
                indegree[j]--;
                if(indegree[j] == 0)
                    queue.add(j);
            }
        }

        return numCourses == count;

    }
}
```