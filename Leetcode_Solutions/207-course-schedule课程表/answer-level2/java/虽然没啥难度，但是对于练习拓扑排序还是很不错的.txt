### 解题思路
虽然没啥难度，但是对于练习拓扑排序还是很不错的

### 代码

```java
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] nodesIndegree = getNodesIndegree(numCourses, prerequisites);
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < nodesIndegree.length; i++) {
            if (nodesIndegree[i] == 0) {
                queue.add(i);
            }
        }

        int count = 0;
        while (!queue.isEmpty()) {
            Integer node = queue.poll();
            count++;
            for (int i = 0; i < prerequisites.length; i++) {
                if (prerequisites[i][1] == node) { //邻居
                    nodesIndegree[prerequisites[i][0]]--;
                    if (nodesIndegree[prerequisites[i][0]] == 0) {
                        queue.add(prerequisites[i][0]);
                    }
                }
            }
        }

        return count == numCourses;
    }

    private int[] getNodesIndegree(int numCourses, int[][] prerequisites) {
        int[] nodesIndegree = new int[numCourses];
        for (int i = 0; i < prerequisites.length; i++) {
            nodesIndegree[prerequisites[i][0]]++;
        }
        return nodesIndegree;
    }
}
```