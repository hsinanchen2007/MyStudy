### 解题思路
这是一个 uniform cost search problem，BFS 可以保证在这种情况下找到最短路径.
graph: <stop, 可以到这一站的所有车list>
这题比较迷惑的地方在于bfs看起来应该以车为单位 但我们还是要一个一个站的处理     
                                    [][][]    [T][][]
									[][][] [][][] [][][] [][][] 
					[][][][] 	[][][]  [][][][]   [][][][] 
									            [S][][]
每一层我们相当于把所有可以乘的车的“所有站点”都加到了queue里 这样这一层的遍历我们相当于看了所有当前可以乘的车
注意：看过的车不要看了！   结果： 过程中数一下换乘几次就可以了



### 代码
```java
class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        if (T == S) return 0;
        HashMap<Integer, List<Integer>> graph = new HashMap<>();//<stop, bus_list>
        for (int i = 0; i < routes.length; i++) {
            for (int j = 0; j < routes[i].length; j++) {
                graph.putIfAbsent(routes[i][j], new LinkedList<Integer>());
                graph.get(routes[i][j]).add(i);//add bus_num to this stop's bus list
            }
        }
        HashSet<Integer> visited = new HashSet<Integer>();
        Queue<Integer> q = new LinkedList<>();//q of stops need to check
        q.offer(S);
        int round = 1;
        while (!q.isEmpty()) {
            for (int num_stops = q.size(); num_stops > 0; num_stops--) {
                int cur_stop = q.poll();
                List<Integer> bus_list = graph.get(cur_stop);
                for (int bus: bus_list) {
                    if (visited.add(bus)) {
                        for (int i = 0; i < routes[bus].length; i++) {
                            int stop = routes[bus][i];
                            if(stop == T) return round;
                            else q.offer(stop);
                        }
                    }
                }
            }
            round++;
        }
        return -1;
    }
}
```