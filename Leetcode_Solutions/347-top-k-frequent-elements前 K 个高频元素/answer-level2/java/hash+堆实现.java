### 解题思路
hash计数维护数出现的频率
k长度极小堆，维护前k个高频元素
得到的list数组，反转即可

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        //list值
        List<Integer> list = new ArrayList();

        //前k个值
        if (nums.length == 0 || k > nums.length) {
            return list;
        }

        //map集合
        Map<Integer, Integer> map = new HashMap();

        //遍历一次数组 hash计数
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }

        //使用优先队列 极小堆
        PriorityQueue<Integer> queue = new PriorityQueue((x,y) -> map.get(x) - map.get(y));

        //遍历map-key 加入优先队列
        for (Integer n : map.keySet()) {
            if (queue.size() < k) {
                queue.add(n);
            } else if (map.get(queue.peek()) < map.get(n)) {
                queue.remove();
                queue.add(n);
            }
        }

        //遍历优先队列 加入queue的值
        while (!queue.isEmpty()) {
            list.add(queue.remove());
        }

        //反转list列表 因为是极小堆 
        Collections.reverse(list);

        return list;
    }
}
```