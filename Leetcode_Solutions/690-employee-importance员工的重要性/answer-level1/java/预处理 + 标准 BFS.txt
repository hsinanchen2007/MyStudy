```java
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        int res = 0;
        if (employees.size() == 0) return res;
        
        // 预处理
        Map<Integer, Employee> map = new HashMap<>();
        for (Employee e : employees) {
            map.put(e.id, e);
        }

        // BFS
        Queue<Integer> queue = new LinkedList<>();
        queue.add(id);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                // 当前领导
                int currId = queue.poll();
                Employee e = map.get(currId);
                if (e != null) {
                    res += e.importance;
                    // 将当前领导的直系下属入队，下一轮搜索
                    for (Integer tempId : e.subordinates) {
                        queue.add(tempId);
                    }
                }
            }
        }
        return res;
    }
}
```