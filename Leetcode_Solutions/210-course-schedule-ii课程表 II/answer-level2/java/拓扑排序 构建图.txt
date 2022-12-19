### 解题思路
1. 记录每个点的出度，当出度为0时，该点可以先选
2. 出度为0的点选走后，更新与该点有关联的点的出度
3. 重复上述过程
我用的是List数组来记录，List[0]记录的是所有指向0的点。

### 代码

```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] result = new int[numCourses];
        //记录出度
        int[] outDegree = new int[numCourses];
        List<Integer>[] lists = new List[numCourses];
        for(int i=0;i < numCourses; i++){
            lists[i] = new ArrayList<>();
            result[i] = i;
        }
        if (prerequisites.length == 0)
            return result;

        for (int[] p : prerequisites) {
            outDegree[p[0]]++;
            lists[p[1]].add(p[0]);
        }
        Queue<Integer> queue = new LinkedList<>();
        int cnt = 0;
        for (int i = 0; i < outDegree.length; i++) {
            if (outDegree[i] == 0)
                queue.add(i);
        }
        while (!queue.isEmpty()){
            Integer poll = queue.poll();
            result[cnt] = poll;
            cnt++;
            for (Integer integer : lists[poll]) {
                outDegree[integer]--;
                if (outDegree[integer] == 0)
                    queue.add(integer);
            }
        }
        if (cnt == numCourses)
            return result;
        return new int[]{};
    }
}
```