####  方法一：贪心
这是一个贪心的问题，唯一的困难是资金在变化导致可投资的项目列表变化。
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNTAyL3VzZXIucG5n?x-oss-process=image/format,png)

这可以通过使用两个数据结构来记录：
- `projects` 记录所有尚未开展的项目。
- `available` 记录当前资金可投资的项目。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNTAyL2RvbmUucG5n?x-oss-process=image/format,png)

**算法：**
- 为了加快速度，首先检查是否存在所有项目都可投资且初始资本 `W >= max(Capital)` 的情况。如果是，返回利润中前 `k` 个最大元素的和。
-  迭代选择 `k` 个项目，每一次选择：
	-  遍历 `N` 个项目，并在 `W>=Capital[j]` 的项目之间进行选择，选择 `Profits[j]` 最大的一个。
	- 如果当前资本不足以启动任意一个项目，则 `break`。
	- 更新 `W += Profits[idx]`，然后标记该项目启动资金为 `Capital[j] = Integer.MAX_VALUE`。
- 返回 `W`。 

```python [solution2-Python]
from heapq import nlargest
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        # to speed up: if all projects are available
        if W >= max(Capital):
            return W + sum(nlargest(k, Profits))
        
        n = len(Profits)
        for i in range(min(n, k)):
            idx = -1 
            # if there are available projects,
            # pick the most profitable one
            for j in range(n):
                if W >= Capital[j]:
                    if idx == -1: 
                        idx = j
                    elif Profits[idx] < Profits[j]: 
                        idx = j
                        
            # not enough capital to start any project
            if idx == -1:
                break
            
            # add the profit from chosen project
            # and remove the project from further consideration
            W += Profits[idx]
            Capital[idx] = float('inf')
            
        return  W
```

```java [solution2-Java]
class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        // to speed up: if all projects are available
        boolean speedUp = true;
        for (int c: Capital) if (W < c) speedUp = false;
        if (speedUp) {
            PriorityQueue<Integer> heap = new PriorityQueue<>();
            for (int p: Profits) {
                heap.add(p);
                if (heap.size() > k) heap.poll();    
            }
            for (int h: heap) W += h; 
            return W;
        }
        
        int idx;
        int n = Profits.length;
        for(int i = 0; i < Math.min(k, n); ++i) {
            idx = -1; 
            // if there are available projects,
            // pick the most profitable one
            for(int j = 0; j < n; ++j) { 
                if (W >= Capital[j]) {
                    if (idx == -1 ) idx = j;
                    else if (Profits[idx] < Profits[j]) idx = j;
                }
            }
            // not enough capital to start any project
            if(idx == -1) break;
            
            // add the profit from chosen project
            // and remove the project from further consideration
            W += Profits[idx];
            Capital[idx] = Integer.MAX_VALUE;                
        }
        return  W;
    }
}
```

**复杂度分析**

* 时间复杂度：若一开始的资本大于全部项目的启动资本则时间复杂度为 $\mathcal{O}(N \log k)$。其他情况为 $\mathcal{O}(\min(k, N) N)$
* 空间复杂度：若一开始的资本大于全部项目的启动资本空间复杂度为：Java 中为 $\mathcal{O}(k)$，在 Python 为 $\mathcal{O}(1)$。其他情况为 $\mathcal{O}(1)$。


####  方法二：利用堆的贪心算法
![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvNTAyL2F2YWlsYWJsZS5wbmc?x-oss-process=image/format,png)

**算法：**
- 为了加快速度，首先检查是否存在所有项目都可投资且初始资本 `W >= max(Capital)` 的情况。如果是，返回利润中前 `k` 个最大元素的和。
- 构造 `projects`：
	- 包含每个项目的启动资金和利润信息。
	- 按启动资金排序。
	- 提供 `pop` 操作以删除已开展的项目。
	- 符合以上条件的结构是 Java 中的最小堆和 Python 中的集合数组。
-  迭代选择 `k` 个项目，每一次选择：
	-  更新当前资金可用的项目列表。可以选择最大堆存储可用的项目，可以马上得到下一个最赚钱的项目。
	- 如果有可投资的项目，选择最赚钱的项目，更新 `W` 并继续。
	- 如果资金不足以启动任何项目就结束。
- 返回 `W` 


```python [solution1-Python]
from heapq import nlargest, heappop, heappush
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        # to speed up: if all projects are available
        if W >= max(Capital):
            return W + sum(nlargest(k, Profits))
        
        n = len(Profits)
        projects = [(Capital[i], Profits[i]) for i in range(n)]
        # sort the projects :
        # the most available (= the smallest capital) is the last one
        projects.sort(key = lambda x : -x[0])
        
        available = []
        while k > 0:
            # update available projects
            while projects and projects[-1][0] <= W:
                heappush(available, -projects.pop()[1])
            # if there are available projects,
            # pick the most profitable one
            if available:
                W -= heappop(available)
            # not enough capital to start any project
            else:
                break
            k -= 1
        return W   
```

```java [solution1-Java]
class Solution {
  public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
    // to speed up: if all projects are available
    boolean speedUp = true;
    for (int c: Capital) if (W < c) speedUp = false;
    if (speedUp) {
      PriorityQueue<Integer> heap = new PriorityQueue<>();
      for (int p: Profits) {
        heap.add(p);
        if (heap.size() > k) heap.poll();
      }
      for (int h: heap) W += h;
      return W;
    }

    int n = Profits.length;
    // sort the projects
    // the most available (= the smallest capital) is the head of the heap
    PriorityQueue<int[]> projects = new PriorityQueue<>((x, y) -> (x[0] - y[0]));
    for(int i = 0; i < n; i++) {
      projects.add(new int[] {Capital[i], Profits[i]});
    }

    // max heap
    PriorityQueue<Integer> available = new PriorityQueue<>((x, y) -> (y - x));
    while (k > 0) {
      // update available projects
      while (!projects.isEmpty() && projects.peek()[0] <= W)
        available.add(projects.poll()[1]);

      // if there are available projects,
      // pick the most profitable one
      if (!available.isEmpty()) W += available.poll();
      // not enough capital to start any project
      else break;
      --k;
    }
    return W;
  }
}
```

**复杂度分析**

* 时间复杂度：最好的情况是一开始所有项目都可以投资，这个时候时间复杂度为 $\mathcal{O}(N \log k)$。否则，需要 $\mathcal{O}(N \log N)$ 的时间来创建和排序项目，更新可用项目的时间不超过 $\mathcal{O}(N \log N)$，计算资本的时间不超过 $\mathcal{O}(k \log N)$ 。因此，总的时间复杂度是 $\mathcal{O}(N \log N + N \log N + k \log N)$，若 $k < N$，则有 $\mathcal{O}(N \log N)$。
* 空间复杂度：$\mathcal{O}(N)$。