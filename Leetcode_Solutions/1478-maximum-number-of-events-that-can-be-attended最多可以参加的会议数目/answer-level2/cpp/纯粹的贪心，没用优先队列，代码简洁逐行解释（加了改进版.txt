### 解题思路
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;发现这么写，比较简单。。。就按照结束时间升序排序即可，然后用个set，对区间从前往后遍历，如果这个点上没安排会议就添加进去。。对于 $100000*[1,100000]$这种例子不太可行，数据水（本人菜鸡大佬们轻喷

**优先队列**参考[这位](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/sao-miao-suan-fa-tan-xin-by-lucifer1004/)老哥的！这是本题**最好**的思路！他写的非常清楚了，我就给大家引路了！

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;我在这补充下我这个为什么要根据结束时间升序排序。。有的小伙伴有点模糊，假设已经安排了一些会议，我们现在再安排的会议肯定是不能和之前冲突的对吧。有这么几种选择
- 安排剩下的里面，具有最早开始时间的
- 安排剩下的里面，持续时间最短的
- 安排剩下的里面，具有最早结束时间的。

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;选择第一种，极端情况是开始很早，持续时间很长，选择第二种，持续时间很短，开始很晚，选择第三种最早结束时间，可以理解为最早开始时间+持续时间也最短，所以按照最早结束时间升序排序就是这么来的。

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;或者这么说，哪个会今天要结束了，我一定得去参加这个，因为别的会，改天能再参加啊，但是这个会，今天没了就没了，所以说这个会我一定要参加，才能保证参加的会最多（滑稽，我才不喜欢开会），这就是贪心。。

### 代码

思路一，时间复杂度 $O(n^2)$
```java []
class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (o1, o2) -> o1[1] - o2[1]);
        Set<Integer> set = new HashSet<>();
        for (int[] event : events) {
            int s = event[0];
            int e = event[1];
            for (int i = s; i <=e; i++) {
                if (!set.contains(i)) {
                    set.add(i);
                    break;
                }
            }
        }
        return set.size();
    }
}
```
```c++ []
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& e1, const vector<int>& e2) {
           return e1[1] < e2[1];
        });

        unordered_set<int> res;
        for(vector<int> e: events) {
            for(int d = e[0]; d <= e[1]; d++) {
                if(res.find(d) == res.end()) {
                    res.insert(d);
                    break;
                }
            }
        }

        return res.size();
    }
};
```
```python []
class Solution:
    def maxEvents(self,events):
        events.sort(key=lambda x:x[1])
        visited = set()
        for s,e in events:
            for day in range(s,e+1):
                if day not in visited:
                    visited.add(day)
                    break
        return len(visited)
```

改进版：在选择结束时间早的先分配的基础上，也要判断区间的可行性，也就是根据右端点选择区间分配，需要用到优先队列，时间复杂度 $O(nlogn)$
```java
    public int maxEvents(int[][] events) {
        //首先排序：开始时间小的在前。这样是方便我们顺序遍历，把开始时间一样的都放进堆
        Arrays.sort(events, (o1, o2) -> o1[0] - o2[0]);
        //小顶堆
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        //结果、开始时间、events下标、有多少组数据
        int res = 0, last = 1, i = 0, n = events.length;
        while (i < n || !pq.isEmpty()) {
            //将start相同的会议都放进堆里
            while (i < n && events[i][0] == last) {
                pq.offer(events[i++][1]);
            }
            //pop掉当前天数之前的
            while (!pq.isEmpty() && pq.peek() < last) {
                pq.poll();
            }
            //顶上的就是俺们要参加的
            if (!pq.isEmpty()) {
                pq.poll();
                res++;
            }
            last++;
        }
        return res;
    }

```