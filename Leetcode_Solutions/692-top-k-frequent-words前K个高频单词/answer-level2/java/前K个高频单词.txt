####  方法一：排序
**算法：**
计算每个单词的频率，并使用使用这些频率的自定义排序关系对单词进行排序。然后取前 `k`。 

```Python [ ]
class Solution(object):
    def topKFrequent(self, words, k):
        count = collections.Counter(words)
        candidates = count.keys()
        candidates.sort(key = lambda w: (-count[w], w))
        return candidates[:k]
```

```Java [ ]
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> count = new HashMap();
        for (String word: words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        List<String> candidates = new ArrayList(count.keySet());
        Collections.sort(candidates, (w1, w2) -> count.get(w1).equals(count.get(w2)) ?
                w1.compareTo(w2) : count.get(w2) - count.get(w1));

        return candidates.subList(0, k);
```


**复杂度分析**

* 时间复杂度：$O(N \log{N})$。其中 $N$ 是 `words` 的长度。我们用 $O(N)$ 时间计算每个单词的频率，然后用 $O(N \log{N})$ 时间对给定的单词进行排序。
* 空间复杂度：$O(N)$，用来存放候答案的地方 


##  方法二：堆
**算法：**
- 计算每个单词的频率，然后将其添加到存储到大小为 `k` 的小根堆中。它将频率最小的候选项放在堆的顶部。最后，我们从堆中弹出最多 `k` 次，并反转结果，就可以得到前 `k` 个高频单词。             
 - 在 Python 中，我们使用 `heapq\heapify`，它可以在线性时间内将列表转换为堆，从而简化了我们的工作。

```Java [ ]
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> count = new HashMap();
        for (String word: words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> heap = new PriorityQueue<String>(
                (w1, w2) -> count.get(w1).equals(count.get(w2)) ?
                w2.compareTo(w1) : count.get(w1) - count.get(w2) );

        for (String word: count.keySet()) {
            heap.offer(word);
            if (heap.size() > k) heap.poll();
        }

        List<String> ans = new ArrayList();
        while (!heap.isEmpty()) ans.add(heap.poll());
        Collections.reverse(ans);
        return ans;
    }
}
```

```Python [ ] 
class Solution(object):
    def topKFrequent(self, words, k):
        count = collections.Counter(words)
        heap = [(-freq, word) for word, freq in count.items()]
        heapq.heapify(heap)
        return [heapq.heappop(heap)[1] for _ in xrange(k)]
```

**复杂度分析**

* 时间复杂度： $O(N \log{k})$。其中 $N$ 是 `words` 的长度。我们用 $O(N)$ 的时间计算每个单词的频率，然后将 $N$ 个单词添加到堆中，添加每个单词的时间为 $O(\log {k})$ 。最后，我们从堆中弹出最多 $k$ 次。因为 $k \leq N$ 的值，总共是 $O(N \log{k})$。
* 空间复杂度：$O(N)$，用于存储我们计数的空间