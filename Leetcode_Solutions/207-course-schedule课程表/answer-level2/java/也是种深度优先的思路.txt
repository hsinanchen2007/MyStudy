# 思路
  判断依赖其他课的课程是否被依赖（是否成环）。
# code
```java
    List<List<Integer>> depens;

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        depens = new ArrayList<>(numCourses);
        for (int i = 0; i < numCourses; i++) {
            depens.add(new ArrayList<>());
        }
        for (int[] pre : prerequisites) {
            depens.get(pre[0]).add(pre[1]);
            if (hasCycle(pre[0], pre[1])) return false;
        }
        return true;
    }

    private boolean hasCycle(int find, int start) {
        List<Integer> list = depens.get(start);
        if (list.size() == 0) return false;
        for (int i : list){
            if (i == find || hasCycle(find, i)) return true;
        }
        return false;
    }
```