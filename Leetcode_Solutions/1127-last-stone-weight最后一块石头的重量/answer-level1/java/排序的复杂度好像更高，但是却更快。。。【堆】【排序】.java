> [更新链接](https://www.zhangjc.site/archives-284/):https://www.zhangjc.site/archives-284/

### 解题思路：

**提示：**

1. `1 <= stones.length <= 30`
2. `1 <= stones[i] <= 1000`

------
**分析：**



- 关键点在于每次都能拿到最重的，并且执行过程中可能产生新的较轻的石头。
- 因此采用优先队列完成（大顶堆）


- 执行用时 : `5 ms`, 在 `Last Stone Weight` 的 `Java` 提交中击败了 `43.52%` 的用户
- 内存消耗 : `34 MB`, 在 `Last Stone Weight` 的 `Java` 提交中击败了 `100.00%` 的用户

------

**代码：**
```java [-Java]
class Solution {
    public int lastStoneWeight(int[] stones) {
        /* 使用优先对列保证每次能拿到最大的数 */
        Queue<Integer> queue = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return (o2 - o1);
            }
        });
        for (int i = 0; i < stones.length; i++) {
            queue.offer(stones[i]);
        }
        while(queue.size() > 1) {
            int x = queue.poll();
            int y = queue.poll();
            int diff = Math.abs(x - y);
            if (diff != 0) {
                queue.offer(diff);
            }
        }
        if (queue.isEmpty()) return 0;
        return queue.peek();
    }
}
```

**复杂度分析：**

时间：$O(NlogN)$

空间：$O(N)$

------


**分析结果：**

- 这个思路在于每次都重新排序，
- 理论上复杂度会更高，但实际更快
- 是因为每次最多只有一对元素逆序吗。。。
------
**解决办法：**

```java [-Java]
class Solution {
    public int lastStoneWeight(int[] stones) {
        int end = stones.length - 1;
        int k = 0;
        while( k != stones.length && k != stones.length - 1 ){
            Arrays.sort(stones);
            int x = stones[end - 1];
            int y = stones[end];
            if( x == y ){
                stones[end - 1] = stones[end] = -1;
                //end -= 2;
                k += 2;
            }else{
                stones[end - 1] = stones[end] - stones[end - 1];
                stones[end] = -1;
                k += 1;
            }
        }
        Arrays.sort(stones);
        return k == stones.length ? 0 : stones[end];
    }
}
```









