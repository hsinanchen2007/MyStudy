### 解题思路
* BFS，把莫名奇妙的x，i，j变量命名修改为有意义变量便于记忆
* 根据C++版本改写过来需要理解一段时间

### 代码

```java
class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        assert routes.length >= 0 && routes.length <= 500;
       if (S == T) return 0;
        int N = routes.length;
        Map<Integer, Set<Integer>> map = new HashMap<>(); // 存储车站能通到哪些路线
        for (int bus = 0; bus < N; ++bus) {
            for (int station : routes[bus]) {
                Set<Integer> busSet = map.putIfAbsent(station,new HashSet<>());
                if (busSet == null) {
                    busSet = map.get(station);
                }
                busSet.add(bus);
            }
        }
        // 哪些路线被遍历过了
        boolean[] visited = new boolean[N];
        // 存储已经遍历过的路线
        Queue<Integer> queue = new LinkedList<>(); 
        Set<Integer> busses = map.get(S);
        for (Integer bus : busses) {
            queue.add(bus);
            visited[bus] = true;
        }
        int step = 0;
        while (!queue.isEmpty()) {
            ++step;
            int s = queue.size();
            for (int i = 0; i < s; ++i) {
                int top = queue.poll();
                for (Integer station : routes[top]) {
                    if (station == T) {
                      return step;  
                    } 
                    for (Integer bus : map.get(station)) {
                        if (!visited[bus]) {
                            queue.add(bus);
                            visited[bus] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```