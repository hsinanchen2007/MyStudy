### 解题思路
大顶堆存放最小的k个，然后遍历大顶堆，反向输出结果
效率不是很高呀，奇怪

### 代码

```java
class Solution {
    public int[] smallestK(int[] arr, int k) {
        if (k == 0) {
            return new int[]{};
        }
        Queue<Integer> priorityQueue = new PriorityQueue(new Comparator() {
            @Override
            public int compare(Object o, Object t1) {
                return (int) t1 - (int) o;
            }
        });
        for (int i = 0; i < arr.length; i++) {
            if (priorityQueue.size() < k) {
                priorityQueue.add(arr[i]);
            } else {
                if (arr[i] < priorityQueue.peek()) {
                    priorityQueue.poll();
                    priorityQueue.add(arr[i]);
                }
            }
        }
        int[] results = new int[priorityQueue.size()];
        int index = priorityQueue.size() - 1;
        while (!priorityQueue.isEmpty()) {
            results[index--] = priorityQueue.poll();
        }
        return results;
    }
}
```