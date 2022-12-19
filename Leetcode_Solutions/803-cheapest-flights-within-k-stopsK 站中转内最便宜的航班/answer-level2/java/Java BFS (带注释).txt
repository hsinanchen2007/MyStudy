```java

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        // 预处理
        // 将数组类型的航班转成 Map<src, List<int[]{dst, cost}>>
        // 方便在 BFS 的时候根据找到 src 可以飞往的城市及其价格
        Map<Integer, List<int[]>> fromCityMap = new HashMap<>();
        for (int[] f : flights) {
            List<int[]> infos = fromCityMap.getOrDefault(f[0], new ArrayList<>());
            infos.add(new int[]{f[1], f[2]});
            fromCityMap.put(f[0], infos);
        }  

        // minCost[x]: 表示到目前为止从城市 src 飞往城市 x 的最低价格
        int[] minCost = new int[n];
        Arrays.fill(minCost, Integer.MAX_VALUE);
        minCost[src] = 0;
        
        // BFS
        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);
        // 记录搜索的深度，用于控制中转站的个数 
        int depth = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int currCity = queue.poll();
                // 拿到当前城市可以飞往的城市及其价格
                List<int[]> toCities = fromCityMap.getOrDefault(currCity, new ArrayList<>());
                // 遍历每一个可以飞往的城市，然后更新最小价格
                for (int[] toCity : toCities) {
                    // 如果中转站的数量已经等于 K 并且当前飞往的城市不是目标城市 dst，
                    // 则不处理这个城市
                    if (depth == K && toCity[0] != dst) continue;
                    // 飞往的城市当前的最小价格大于上一个城市当前的最小价格加上飞往的城市的价格
                    // 则更新飞往的城市当前的最小价格
                    if (minCost[toCity[0]] > minCost[currCity] + toCity[1]) {
                        minCost[toCity[0]] = minCost[currCity] + toCity[1];
                        // 入队，进行下一轮的 BFS
                        queue.add(toCity[0]);
                    }
                }
            }
            depth++;
        }
        // 返回到达 dst 的最小的价格
        return minCost[dst] == Integer.MAX_VALUE ? -1 : minCost[dst];
    }
}
```