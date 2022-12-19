### 解题思路
1、Map记录arr中所有元素和元素的频次；
2、自定义一个优先队列，比较的依据是Map.Entry中的value，也就是频次；
3、循环k次，把map中前k个元素加入队列，并将这些元素删除，此时queue中是一个最小二叉堆，根节点为最小的节点；
4、map中剩下的元素继续遍历，如果比当前queue的头节点大，则替换；
5、最后，因为queue是最小二叉树，所以根据题目要求，倒序放入数组并转成list返回。

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < nums.length; i++) {
            Integer freq = map.get(nums[i]);
            if (freq == null) {
                map.put(nums[i], 1);
            }
            else {
                map.put(nums[i], freq + 1);
            }
        }
        
        PriorityQueue<Map.Entry<Integer, Integer>> queue =
                new PriorityQueue<>(map.size(), new Comparator<Map.Entry<Integer, Integer>>() {

            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                if (o1.getValue() > o2.getValue()) {
                    return 1;
                }
                else if (o1.getValue() < o2.getValue()) {
                    return -1;
                }
                else {
                    return 0;
                }
            }
        });

        int i = 0;
        Iterator<Map.Entry<Integer, Integer>> iterator = map.entrySet().iterator();
        while (i < k) {
            Map.Entry<Integer, Integer> entry = iterator.next();
            queue.add(entry);
            iterator.remove();

            i++;
        }
        

        for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
            if (entry.getValue() > queue.peek().getValue()) {
                queue.poll();
                queue.add(entry);
            }
        }
        
        Integer[] arr = new Integer[queue.size()];
        int j = queue.size();
        for (Map.Entry<Integer, Integer> entry: queue) {
            arr[j - 1] = entry.getKey();
            j--;
        }


        return Arrays.asList(arr);
    }
}
```