使用java内置的优先队列，但由于java中是默认的最小堆，所以需要对comparator作一点儿改变。
1，判断堆的size是否大于1. 若大于1，则poll出最大的两个值，若不相同，则add两个值的差值。若相同不操作。<while>
2，最后判断size，若size == 0则输出0， 若不为0.则输出最大值。
```
class Solution {
    public int lastStoneWeight(int[] stones) {
        // 利用java中内置堆（最小堆）
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>((n1, n2) -> n2 - n1);
        for (int n:stones) queue.add(n);

        while (queue.size() > 1) {
            int a = queue.poll();
            int b = queue.poll();
            if ( a != b) queue.add(a - b);
        }
        if (queue.size() == 0) return 0;
        else return queue.peek();
    }
}
```
