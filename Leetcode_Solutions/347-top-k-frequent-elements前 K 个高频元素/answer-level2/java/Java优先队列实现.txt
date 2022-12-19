Java使用优先队列实现
```
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        int size = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        PriorityQueue<Map.Entry<Integer,Integer>> heap = new PriorityQueue<>(k, new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o1.getValue().compareTo(o2.getValue());
            }
        });
        for (int num : nums) {
            if (map.keySet().contains(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num,1);
            }
        }

        for (Map.Entry<Integer,Integer> entry : map.entrySet()){
            heap.add(entry);
            ++size;
            if (size > k) {
                heap.poll();
            }
        }
        List<Integer> list = new ArrayList<>(k);
        for (Map.Entry<Integer,Integer> entry : heap){
            list.add(entry.getKey());
        }

        return list;
    }
}
```
