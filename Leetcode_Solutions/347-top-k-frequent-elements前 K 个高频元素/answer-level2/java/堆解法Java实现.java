```
class Solution {
     public static List<Integer> topKFrequent(int[] nums, int k) {
        //构建hashmap，存储每个数字；
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i : nums) {
            hashMap.put(i, hashMap.getOrDefault(i, 0) + 1);
        }
        //构建最小堆,利用lambda表达式反序；
        PriorityQueue<Integer> heap = new PriorityQueue<>(((o1, o2) ->hashMap.get(o1) - hashMap.get(o2)));
        //输入并调整堆直到剩下k个元素；
        for (int i : hashMap.keySet()) {
            heap.add(i);
            if (heap.size() > k) {
                heap.poll();
            }
        }
        //保存剩余的k个数值，并返回List中；
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            list.add(heap.poll());
        }
        Collections.reverse(list);
        return list;
    }
}
```
