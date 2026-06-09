```
public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(stones.length, (i1, i2) -> i2 - i1);//建立最大堆
        Arrays.stream(stones).forEach(i -> queue.add(i));//将数组填充到堆中
        while (queue.size() > 1) {//只要堆中数据的个数大于等于2，就一直执行循环
            //连续两次出堆（就是两个最大的值），如果值相同，本次循环结束；如果值不同，再将差值添加到堆中
            Integer first = queue.poll();
            Integer second = queue.poll();
            if (first != second) {
                queue.add(first - second);
            }
        }
        if (queue.isEmpty()) {//如果堆中没数据了，返回0即可
            return 0;
        }
        return queue.peek();//如果还有数据，返回仅剩的一个数据
    }
```
