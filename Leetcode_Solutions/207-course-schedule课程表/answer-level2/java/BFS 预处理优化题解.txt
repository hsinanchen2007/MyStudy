```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // 预处理
        // 将前置课程作为 key，所以将这个课程 key 作为前置课程的课程作为 value
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int[] req : prerequisites) {
            List<Integer> list = map.getOrDefault(req[1], new ArrayList<>());
            list.add(req[0]);
            map.put(req[1], list);
        }
        // 计算每门课的入度
        int[] indegress = new int[numCourses];
        for (int[] cp : prerequisites) indegress[cp[0]]++;

        // 将入度为 0 的课程放入到队列中
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegress[i] == 0) queue.add(i);
        }

        // BFS
        while (!queue.isEmpty()) {
            Integer pre = queue.poll();
            numCourses--;
            // 拿到将 pre 作为前置课程的所有的课程
            for (int i : map.getOrDefault(pre, new ArrayList<>())) {
                // 入度减一
                // 如果入度等于 0， 则将这个课程放到队列中，下次循环搜索
                if (--indegress[i] == 0) queue.add(i);
            }
        }

        return numCourses == 0;
    }
}
```