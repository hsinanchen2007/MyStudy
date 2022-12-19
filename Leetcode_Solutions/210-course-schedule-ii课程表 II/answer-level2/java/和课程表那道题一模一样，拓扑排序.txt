### 解题思路
和课程表那道题一模一样，拓扑排序

### 代码

```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] res = new int[numCourses];
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
            res[count] = node;
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

        if(count != numCourses){
            return new int[0];
        }
        return res;
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