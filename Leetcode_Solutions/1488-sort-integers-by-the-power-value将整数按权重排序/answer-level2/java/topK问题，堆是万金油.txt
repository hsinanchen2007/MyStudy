### 解题思路
排序的top K问题，用堆这个数据结构，是万金油的问题，求最小K是大顶堆，求最大K是小顶堆。java中对应的就是优先队列。

用大顶堆最后输出顶部，就是第K个元素。

ps:比赛的时候没有做缓存，直接算每个权值，耗时23ms，效率也不是太感人。这里感觉好像是可以用上缓存，全局静态缓存都行，因为一个这题中，任何一个数的权值，都是永远固定的。

### 代码

```java
class Solution {
    public int getKth(int lo, int hi, int k) {
        // 大顶堆
        Queue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            if (o1[1] == o2[1]){
                return o2[0]-o1[0];
            }
            return o2[1] - o1[1];
        });
        for (int i = lo;i<= hi;i++){
            int[] arr = new int[2];
            int temp = i;
            int count = 0;
            while (temp != 1){
                if ((temp & 1) == 0){
                    temp = temp >> 1;
                }else {
                    temp = 3*temp + 1;
                }
                count++;
            }
            arr[0] = i;
            arr[1] = count;
            if (pq.size() < k){
                pq.offer(arr);
            }else {
                int[] top = pq.peek();
                if (arr[1] < top[1] || (arr[1] == top[1] && arr[0] < top[0])){
                    pq.poll();
                    pq.offer(arr);
                }
            }
        }
        return pq.poll()[0];
    }
}
```