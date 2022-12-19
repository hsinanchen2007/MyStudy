整理思路与 topK 类似，不同的是，需要排序的是距离原点的距离，输出的是点的坐标，二者之间有一个关联。
用一个大顶堆保存具体原点的 K 个点，另外用一个 Map 保存距离与输入数组下标之间的关联，注意一个距离可能对应了多个点，也就是多个下标
```
    public int[][] kClosest(int[][] points, int K) {
        if (points == null || points.length < K) return points;
        // 保存距离与点之间的映射，因为比较K个点的指标为距离，而我们的目标是要找到K个点，这里的value是点的横坐标
        // 这里有一个问题，就是相同距离的可能有多个点
        Map<Long, List<Integer>> map = new HashMap<>(K);
        // 大顶堆
        PriorityQueue<Long> queue = new PriorityQueue<>(new Comparator<Long>() {
            public int compare(Long a, Long b) {
                return a > b ? -1 : a == b ? 0 : 1;
            }
        });
        for (int i = 0; i < points.length; i++) {
            long distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            // 此时堆中的元素还不足 K 个，所以直接添加到堆中
            if (i < K) {
                List<Integer> tmpList = map.getOrDefault(distance, new ArrayList<>());
                tmpList.add(i);
                map.put(distance, tmpList);
                queue.offer(distance);
            } else {
                // 当当前元素 < 堆顶时，则删除堆顶，将当前元素加入，否则则放弃当前节点

                // 注意这里的 K 不是相对于优先队列中的元素个数来说的
                if (distance < queue.peek()) {
                    Long peek = queue.peek();
                    // 如果队列中只有一个元素，则删除这个队列
                    if (map.get(peek).size() == 1) {
                        map.remove(peek);
                    } else {
                        // 删除队列中的一个元素
                        map.get(peek).remove(map.get(peek).size() - 1);
                    }
                    queue.poll();
                    // 把新元素插入
                    queue.offer(distance);
                    List<Integer> tmpList = map.getOrDefault(distance, new ArrayList<>());
                    tmpList.add(i);
                    map.put(distance, tmpList);
                }
            }
        }
        int[][] result = new int[K][2];
        int cur = 0;
        for (List<Integer> tmpL : map.values()) {
            for (int j : tmpL) {
                result[cur++] = new int[]{points[j][0], points[j][1]};
            }
        }
        return result;
    }
```
