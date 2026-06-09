### 解题思路
解答是参考的高赞的解决方案
我自己用的是BFS来寻找最小费用，超时不通过，不知道怎么优化，就看了大佬的想法。
谈一下下面这个解答
利用最小堆来存储层次遍历的结果，每次将费用最小的站弹出去，确实是一个很好的解决方案

### 代码

```java
class Solution {
   public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        if (src == dst)
            return 0;
        Map<Integer,Map<Integer, Integer>> map = new HashMap<>();
        for (int[] flight : flights) {
            if (map.containsKey(flight[0])){
                Map<Integer, Integer> temp = map.get(flight[0]);
                temp.put(flight[1], flight[2]);
            }
            else{
                Map<Integer,Integer> temp = new HashMap<>();
                temp.put(flight[1], flight[2]);
                map.put(flight[0], temp);
            }
        }
        //始终维护一个费用的最小堆
        //存储最低费用、到达站、中转次数
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        pq.offer(new int[]{0, src, 0});
        while (!pq.isEmpty()){
            int[] temp = pq.poll();
            int fee = temp[0];
            int tar = temp[1];
            int k = temp[2];
            if (tar == dst)
                return fee;
            if (k <= K){
                Map<Integer, Integer> integerMap = map.get(tar);
                if (integerMap != null){
                    Set<Map.Entry<Integer, Integer>> entries = integerMap.entrySet();
                    Iterator<Map.Entry<Integer, Integer>> iterator = entries.iterator();
                    while (iterator.hasNext()){
                        Map.Entry<Integer, Integer> next = iterator.next();
                        pq.offer(new int[]{fee+next.getValue(), next.getKey(), k+1});
                    }
                }
            }
        }
        return -1;
    }
}
```