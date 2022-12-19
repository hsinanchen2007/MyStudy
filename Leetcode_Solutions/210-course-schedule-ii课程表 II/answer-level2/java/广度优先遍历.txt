### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        if (numCourses == 0) {
            return new int[0];
        }

        int[] inDegree = new int[numCourses];
        for (int[] p : prerequisites) {
            inDegree[p[0]]++;
        }

        LinkedList<Integer> queue = new LinkedList();
        for (int i=0; i<numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.addLast(i);
            }
        }

        List<Integer> res = new ArrayList();
        while (!queue.isEmpty()) {
            int num = queue.removeFirst();
            res.add(num);

            for (int[] p : prerequisites) {
                if (num == p[1]) {
                    inDegree[p[0]]--;
                    if (inDegree[p[0]] == 0) {
                        queue.addLast(p[0]);
                    }
                }
            }
        }

        if (res.size() == numCourses) {
            int[] ans = new int[numCourses];
            for (int i=0; i<numCourses; i++) {
                ans[i] = res.get(i);
            }
            return ans;
        } else {
            return new int[0];
        }
    }
}
```