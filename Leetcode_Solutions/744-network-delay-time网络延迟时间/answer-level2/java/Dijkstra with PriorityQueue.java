```
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, List<int[]>> map = new HashMap<>();

        for (int[] arr : times) {
            List<int[]> list = map.getOrDefault(arr[0], new ArrayList<>());
            list.add(new int[]{arr[1], arr[2]});

            map.put(arr[0], list);
        }

        int[] distance = new int[N+1];
        Arrays.fill(distance,Integer.MAX_VALUE);

        boolean[] visited = new boolean[N+1];
        distance[K] = 0;
        distance[0] = 0;
        PriorityQueue<Integer> queue = new PriorityQueue<>((a, b)-> distance[a] - distance[b]);
        queue.offer(K);

        while (!queue.isEmpty() ) {
            int idx = queue.poll();
            visited[idx] = true;
            List<int[]> next = map.getOrDefault(idx, Collections.emptyList());
            for (int[] arr: next) {
                if (visited[arr[0]]) continue;
                distance[arr[0]] = Math.min(distance[arr[0]], arr[1] + distance[idx]);
                queue.remove(arr[0]);
                queue.offer(arr[0]);
            }
        }

        int res = Arrays.stream(distance).max().getAsInt();
        return res == Integer.MAX_VALUE ? -1 : res;
    } 
}
```
