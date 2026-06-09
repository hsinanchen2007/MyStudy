# 思路
将所有值都加入到优先队列（小顶堆）中，每次从优先队列中取出两个数相加，然后将相加的值再加入到优先队列中，不断重复这个过程，直到优先队列只剩下一个元素为止。这其中产生的费用就是最小费用。其实实质上是贪心算法，只是利用了优先队列来获取最新的最小的两个值。

```java
  public int connectSticks(int[] sticks) {
        if (sticks.length == 1) {
            return 0;
        }

        PriorityQueue<Integer> queue = new PriorityQueue<>();

        for (int stick : sticks) {
            queue.add(stick);
        }

        int ans = 0;
        while (!queue.isEmpty()) {
            Integer first = queue.poll();
            if (queue.isEmpty()) {
                break;
            }
            int second = queue.poll();
            int sum = first + second;
            ans += sum;
            queue.add(sum);
        }

        return ans;
    }
    
```