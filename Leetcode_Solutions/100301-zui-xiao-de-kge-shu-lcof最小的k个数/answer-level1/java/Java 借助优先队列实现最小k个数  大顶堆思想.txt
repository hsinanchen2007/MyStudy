### 解题思路
思路：大顶堆
Java中使用优先队列即可，默认是小顶堆，需要修改比较器规则
需要申请一个k大小的优先队列以及一个存储最终返回对象的int数组

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        // 默认是小根堆，实现大根堆需要重写一下比较器
        Queue<Integer> queue = new PriorityQueue<>((v1, v2) -> v2 - v1);
        for (int num : arr) {
            // 如果大小小于k则直接添加新元素即可
            if (queue.size() < k) {
                queue.offer(num);
            }
            // 如果大小等于k，则此时对每一个元素需要和peek进行比较
            // 大于peek则忽略，小于peek则需要删除peek并添加新元素
            else if (num < queue.peek()) {
                queue.poll(); // 堆顶元素出队
                queue.offer(num); // 将新元素加入优先队列，内部会进行调整
            }
        }
        
        // 返回堆中的元素
        int[] result = new int[queue.size()];
        int index = 0;
        for(int num : queue) {
            result[index++] = num;
        }
        return result;
    }
}
```