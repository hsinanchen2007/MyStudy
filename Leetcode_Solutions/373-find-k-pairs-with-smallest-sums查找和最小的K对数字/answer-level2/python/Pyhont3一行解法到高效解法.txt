### 解法一：暴力
枚举所有组合，按照和排序，最后返回前 K 项。
![组合1.png](https://pic.leetcode-cn.com/c6e8cfde2aa085ed377abba0373124247626f6ecbec347aa80f156ac7ff4f78d-%E7%BB%84%E5%90%881.png)
```python3
def kSmallestPairs(self, nums1, nums2, k):
    return sorted(itertools.product(nums1, nums2), key=sum)[:k]
```
### 解法二：暴力标准解
这个解法更加标准，因为上面的解法生成的是元组不是列表。
```python3
def kSmallestPairs(self, nums1, nums2, k):
    return map(list, sorted(itertools.product(nums1, nums2), key=sum)[:k])
```
### 解法三：优化的暴力
仍然遍历所有对，但仅使用生成器和使用大小为 k 的堆`heapq.nsmallest`。 因此，这仅需要$O(k)$的额外内存和$O(mn log k)$的时间。
```
def kSmallestPairs(self, nums1, nums2, k):
    return map(list, heapq.nsmallest(k, itertools.product(nums1, nums2), key=sum))
```
### 解法四：堆
不计算整个矩阵，而将每一行变成三元组`[u + v，u，v]`的生成器，仅在要求计算下一行时才计算下一行，然后将这些生成器与堆合并。 占用 $O(m + k * log(m))$ 的时间复杂度和 $O(m)$ 的空间复杂度。
```python3
def kSmallestPairs(self, nums1, nums2, k):
    streams = map(lambda u: ([u+v, u, v] for v in nums2), nums1)
    stream = heapq.merge(*streams)
    return [suv[1:] for suv in itertools.islice(stream, k)]
```
### 解法五：优先队列
它仅从矩阵左上角的第一对开始，然后根据需要从那里开始扩展。 每当将一对选择为输出结果时，该行中的下一对就会添加到当前选项的优先队列中。 同样，如果所选对是该行中的第一对，则将下一行中的第一对添加到队列中。
![组合2.png](https://pic.leetcode-cn.com/cba00e2cb2cf8a1158aa8caff0c42259a0263bbb5e623e99c2280da21bdd875d-%E7%BB%84%E5%90%882.png)
```python3
class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        queue = []
        def push(i, j):
            if i < len(nums1) and j < len(nums2):
                heapq.heappush(queue, [nums1[i] + nums2[j], i, j])
        push(0, 0)
        pairs = []
        while queue and len(pairs) < k:
            _, i, j = heapq.heappop(queue)
            pairs.append([nums1[i], nums2[j]])
            push(i, j + 1)
            if j == 0:
                push(i + 1, 0)
        return pairs
```

PS：想要一起努力的童鞋们可以关注我创办的公众号：腐烂的橘子🍊，致力于摆脱算法的抽象思维，彻底搞懂算法，同时公众号还会发布面试中的高频知识点，一起努力吧！😋