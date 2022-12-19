```
class Solution {
    public int minJumps(int[] arr) {
        // 初始化 
        int n = arr.length;
        Map<Integer, List<Integer>> map = new HashMap<>();  // 记录同值的索引列表
        int[] dist = new int[n];
        boolean[] canJumpSameVal = new boolean[n];
        Arrays.fill(canJumpSameVal, true);  // 初始化所有位置都可以进行同值跳跃
        for (int i = 0; i < n; i++) {
            List<Integer> orDefault = map.computeIfAbsent(arr[i], key -> new ArrayList<>());
            orDefault.add(i);
        }
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        Queue queue = new LinkedList();
        queue.add(0);
        dist[0] = 0;
        while (!queue.isEmpty()) {
            Integer x = (Integer) queue.poll();
            if (x - 1 >= 0 && dist[x - 1] == Integer.MAX_VALUE) {
                queue.add(x - 1);
                dist[x - 1] = dist[x] + 1;
            }
            if (x + 1 < n && dist[x + 1] == Integer.MAX_VALUE) {
                queue.add(x + 1);
                dist[x + 1] = dist[x] + 1;
            }
            if (canJumpSameVal[x]) {
                for (int tmp : map.get(arr[x])) {
                    if (dist[tmp] == Integer.MAX_VALUE) {
                        dist[tmp] = dist[x] + 1;
                        queue.add(tmp);
                        // 同值跳跃只进行一次
                        canJumpSameVal[tmp] = false;
                    }
                }
            }
        }
        return dist[n - 1];
    }
}
```
