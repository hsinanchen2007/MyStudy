# 思路

这题我觉得是这期中最优价值的一道题，WA了两三次才做出来。

我看了一些其他的题解，发现有的题解很依赖于数据，跑不通一些极端的例子，比如：
* [题解1](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/tan-xin-pai-xu-by-joseph1314/)
    如果输入是{[1,1],[1,2],...,[1,100000]}就会超时
* [题解2](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/java-you-xian-dui-lie-fa-by-yafeites/)
    如果输入是示例5拓展到10^5次方也会超时

PS: 这里没有怼的意思，我从这些题解中也学习到很多，在这里只是阐述一下

那么如何做到不依赖输入数据呢？

我们分析一下，对于某一天我可以参加的所有会议中，我肯定会选择最早结束的那个，因此贪心的思想就出现了：每次选择最小的那个可以用堆来维护可选择会议的结束时间来实现。

然后我们将会议本身按照开始时间升序排序，目的是用于更新`有效会议堆`和`有效与会日期`。每到一天可以选择时首先将所有可选择会议(还没加入堆中)的结束时间加至堆中，选择最小的结束时间作为选定的会议，以此类推

# 时间复杂度
每个结束时间会且仅会进出堆一次，而且每次循环都会从堆中取一个数据，再加上排序和堆维护的开销，因此时间复杂度为`O(nlgn)`,这个算法不依赖于输入。

# 代码
```
class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b){
                return a[0] - b[0];
            }
        });
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        int day = 0, id = 0, n = events.length, res = 0;
        while(id < n || !queue.isEmpty()){
            if(queue.isEmpty()){
                queue.add(events[id][1]);
                day = events[id++][0];
            }
            while(id < n && events[id][0] <= day){
                queue.add(events[id++][1]);
            }
            if(queue.peek() >= day){
                day++;
                res++;
            }
            queue.poll();    
        }
        return res;
    }
}
```

# 改进
利用数据的范围的话，可以将代码写得更简洁，改进为
```
class Solution {
    public int maxEvents(int[][] events) {
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
        Arrays.sort(events, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b){
                return a[0] - b[0];
            }
        });
        int i = 0, res = 0, n = events.length;
        for (int d = 1; d <= 100000; ++d) {
            while (i < n && events[i][0] == d){
                queue.offer(events[i++][1]);
            }
            while (queue.size() > 0 && queue.peek() < d){
                queue.poll();
            }
            if (queue.size() > 0) {
                queue.poll();
                res++;
            }
        }
        return res;
    }
}
```