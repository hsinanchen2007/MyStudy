### 解题思路
无奈自己写的代码就是无法通过所有的测试用例，参考了高赞的大佬，题目其实不难。

### 代码

```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
       if (prerequisites.length == 0)
           return true;
        //出度 记录这个课程需要多少个pre课程
        // 当出度为0 代表这个课程可以修
       int[] outDegree = new int[numCourses];
       HashSet<Integer>[] adj = new HashSet[numCourses];
       for(int i = 0;i < numCourses;i++){
           adj[i] = new HashSet<>();
       }
        for (int[] p : prerequisites) {
            outDegree[p[0]]++;
            adj[p[1]].add(p[0]);
        }
        Queue<Integer> queue = new LinkedList<>();
        //首先增加出度为0的节点
        for(int i = 0;i<numCourses;i++){
            if (outDegree[i] == 0)
                queue.add(i);
        }
        int cnt = 0;
        while (!queue.isEmpty()){
            Integer top = queue.poll();
            cnt++;
            for (Integer integer : adj[top]) {
                outDegree[integer]--;
                if (outDegree[integer] == 0)
                    queue.add(integer);
            }
        }
        return cnt == numCourses;
    }
}
```