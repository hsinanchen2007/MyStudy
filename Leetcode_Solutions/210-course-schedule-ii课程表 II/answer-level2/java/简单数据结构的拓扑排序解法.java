### 解题思路
使用course这个数组用于控制拓扑图的出度以及删边。
使用queue来存储入度为零的点来删除。

### 代码

```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // 保存入度数量
        int[] result = new int[numCourses];
        int[] course = new int[numCourses];

        // 保存入度为0的数据
        Queue<Integer> queue = new LinkedList<>();

        //计算边关系
        Arrays.fill(course,0);
        // 构造topoLogic
        for (int[] pre: prerequisites) {
            course[pre[0]] ++;
        }

        //放入为零的入参
        for (int i = 0; i < course.length; i++) {
            if (course[i] == 0) {
                queue.add(i);
            }
        }

        if (queue.isEmpty())
            return new int[0];

        int j = 0;
        while(!queue.isEmpty()) {
            int out = queue.poll();
            result[j++] = out;
            course[out] = -1;
            // 重新输入queue
            if (j != numCourses) {
                for (int[] pre: prerequisites) {
                    if (pre[1] == out && course[pre[0]] != -1) {
                        if (course[pre[0]] != 0 ) {
                            course[pre[0]]--;
                        }
                        if (course[pre[0]]==0) {
                            queue.add(pre[0]);
                        }
                    }
                }
            }
        }

        if (j != numCourses)
            return new int[0];

        return result;
    }

}
```