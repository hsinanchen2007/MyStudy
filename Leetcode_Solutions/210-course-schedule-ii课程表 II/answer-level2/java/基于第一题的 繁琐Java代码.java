```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        if (!canFinish(numCourses, prerequisites)) {
            int[] res = {};
            return res;
        }
        List<Integer> courceOrder = new ArrayList<>();
        int[] scheduleCources = new int[numCourses];
        boolean[] visited = new boolean[numCourses];
        for (int i = 0; i < prerequisites.length; i++) {
            scheduleCources[prerequisites[i][0]]++;
        }
        for (; ; ) {
            int i = 0;
            boolean flag = false;
            Set<Integer> set = new HashSet<>();
            for (i = 0; i < numCourses; i++) {
                if (!visited[i] && scheduleCources[i] == 0) {
                    flag = true;
                    visited[i] = true;
                    set.add(i);
                }
            }
            if (!flag) {
                break;
            }
            courceOrder.addAll(set);

            for (int k = 0; k < prerequisites.length; k++) {
                if (set.contains(prerequisites[k][1])) {
                    scheduleCources[prerequisites[k][0]]--;
                }
            }

        }
        int[] res = new int[courceOrder.size()];
        for (int i = 0; i < res.length; i++) {
            res[i] = courceOrder.get(i);
        }
        return res;
    }
    private boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] scheduleCources = new int[numCourses];
        boolean[] visited = new boolean[numCourses];
        for (int i = 0; i < prerequisites.length; i++) {
            scheduleCources[prerequisites[i][0]]++;
        }
        for (; ; ) {
            int i = 0;
            for (i = 0; i < numCourses; i++) {
                if (!visited[i] && scheduleCources[i] == 0) {
                    break;
                }
            }
            if (i == numCourses) {
                break;
            }
            // update
            for (int k = 0; k < prerequisites.length; k++) {
                if (prerequisites[k][1] == i) {
                    scheduleCources[prerequisites[k][0]]--;
                }
            }
            visited[i] = true;
        }
        for (int i = 0; i < scheduleCources.length; i++) {
            if (scheduleCources[i] > 0) {
                return false;
            }
        }
        return true;
    }
}
```