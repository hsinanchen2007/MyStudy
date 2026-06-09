### 方法一：排序法
此方法是最简单直接的一个方法，我们将添加的数保存在数组中，返回中位数时，只需将数组排序，返回中间位置数即可。

本题难度为 **困难**，显然一定存在更加优化的方法。
#### 代码（C++ 超时）
```python []
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.store = []

    def addNum(self, num: int) -> None:
        self.store.append(num)

    def findMedian(self) -> float:
        self.store.sort()
        n = len(self.store)
        if n & 1 == 1: # n 是奇数
            return self.store[n // 2]
        else:
            return (self.store[n // 2 - 1] + self.store[n // 2]) / 2
```

```C++ []
class MedianFinder {
    vector<double> store;

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        store.push_back(num);
    }

    // Returns the median of current data stream
    double findMedian()
    {
        sort(store.begin(), store.end());

        int n = store.size();
        return (n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5);
    }
};
```

#### 复杂度分析：
- 时间复杂度：${\mathcal{O}}(nlogn)$。`addNum()` 函数消耗 ${\mathcal{O}}(1)$ 的时间复杂度，`findMedian()` 函数使用了排序，时间复杂度为 ${\mathcal{O}}(nlogn)$。因此总的时间复杂度为 ${\mathcal{O}}(1)+{\mathcal{O}}(nlogn)={\mathcal{O}}(nlogn)$。
- 空间复杂度：${\mathcal{O}}(n)$。

### 方法二：二分查找插入
方法一的缺点在于对数组进行了排序操作，导致时间复杂度较高，假如每次插入一个值前数组已经排好序了呢？这样我们只需考虑每次将值插在合适的位置即可，所以使用二分查找来找到这个合适的位置，会将时间复杂度降低到 ${\mathcal{O}}(n)$（查找: ${\mathcal{O}}(log n)$，插入: ${\mathcal{O}}(n)$）。

#### 代码

```python []
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.store = []

    def addNum(self, num: int) -> None:
        if not self.store:
            self.store.append(num)
        else:
            bisect.insort_left(self.store, num) # 插入

    def findMedian(self) -> float:
        n = len(self.store)
        if n & 1 == 1:  # n是奇数
            return self.store[n // 2]
        else:
            return (self.store[n // 2] + self.store[n // 2 - 1]) / 2
```
```C++ []
class MedianFinder {
    vector<int> store; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};
```
#### 复杂度分析
- 时间复杂度：${\mathcal{O}}(n)$。${\mathcal{O}}(log n)+{\mathcal{O}}(n)≈O(n)$。
- 空间复杂度：${\mathcal{O}}(n)$。使用了数组保存输入。
### 方法三：优先队列（堆）
【[什么是优先队列](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/xiang-jie-you-xian-dui-lie-tan-xin-suan-fa-by-z1m/)】

我们将中位数左边的数保存在大顶堆中，右边的数保存在小顶堆中。这样我们可以在 ${\mathcal{O}}(1)$ 时间内得到中位数。

注意：Python 中没有大顶堆，只能将值取负保存在小顶堆来模拟。为了方便理解，将堆用优先队列表示，如下图。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/93dae43ac85d81bc27115a2383c941919d64ba8d432dead87119c484ef8d6b2f-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/3a53ac9ee812c8d375cba058da2aad1c97707f58a80cb96b8bb38f1a0446f24b-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/bcd5db2277e5531a57db24c390bdd53ddf42ee547556713932a3848514b6f0b7-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/d57c41eeab0b29b21fe8f3dac3c1cfb840f6ed47703c20f2e7596cd363556eb8-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/69fee2fc3a96a190a58f9a97d53a541041e7e05cf0a21e6ab71ac3f87725600f-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/803236bab18997fbe19528f79de055b17265f891301de3b6c7318b363333a32b-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/1799adff94635268f3887512beb3779d09f50ca2343550162700527913cee036-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/4f2519d29f62392ec7bcb2b4f59f6575aee990a7d8d304be2240bf877a8ef400-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/1e3b706d7810508a409f564a41c1b258f4e8e9a1d1594d059589fa7d296a0807-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/861479bca792e227f0fa28eda1900c3993731002378372aff5e3fefd1c7380df-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/8d9bb1b78d610569f256098e36bee209d0f69f4dbe12f582882f75dd63a4a1a4-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG),![幻灯片12.JPG](https://pic.leetcode-cn.com/30dccd401504b18c73d0b0b895ac13c690a2e2493398d344648636a9069359b0-%E5%B9%BB%E7%81%AF%E7%89%8712.JPG),![幻灯片13.JPG](https://pic.leetcode-cn.com/0970540a6662a60715ce0773c6bb2edee4f296ccd35c8fa63dca6b55d90280d9-%E5%B9%BB%E7%81%AF%E7%89%8713.JPG),![幻灯片14.JPG](https://pic.leetcode-cn.com/88767d693bf83d135864f292c0e4eb041b770390f00534fd95dfd4d00ad9b234-%E5%B9%BB%E7%81%AF%E7%89%8714.JPG),![幻灯片15.JPG](https://pic.leetcode-cn.com/e5e64aef8cc0202d6606e9693044c385e2a4da63546167c3cc58dfb731c7464d-%E5%B9%BB%E7%81%AF%E7%89%8715.JPG),![幻灯片16.JPG](https://pic.leetcode-cn.com/56fc6f1fb6ee420eee1bd54a94353a4de45862e4d70af5c4301b00e2dd7d5262-%E5%B9%BB%E7%81%AF%E7%89%8716.JPG),![幻灯片17.JPG](https://pic.leetcode-cn.com/03584875f43ebf1ae8ff9565a1def78ad0cdff778e6d43a1bec52398ce7037cb-%E5%B9%BB%E7%81%AF%E7%89%8717.JPG),![幻灯片18.JPG](https://pic.leetcode-cn.com/069056fbd5d83a8fc6561254c76aef6e13b71920b1d7f3aef4f78afb69822bc6-%E5%B9%BB%E7%81%AF%E7%89%8718.JPG),![幻灯片19.JPG](https://pic.leetcode-cn.com/09c097d2138f83d67ed7a42e68e15191f3ed75b219ffd1717445e075bc402030-%E5%B9%BB%E7%81%AF%E7%89%8719.JPG)>


#### 代码
```python []
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # 初始化大顶堆和小顶堆
        self.max_heap = []
        self.min_heap = []

    def addNum(self, num: int) -> None:
        if len(self.max_heap) == len(self.min_heap):# 先加到大顶堆，再把大堆顶元素加到小顶堆
            heapq.heappush(self.min_heap, -heapq.heappushpop(self.max_heap, -num))
        else:  # 先加到小顶堆，再把小堆顶元素加到大顶堆
            heapq.heappush(self.max_heap, -heapq.heappushpop(self.min_heap, num))

    def findMedian(self) -> float:
        if len(self.min_heap) == len(self.max_heap):
            return (-self.max_heap[0] + self.min_heap[0]) / 2
        else:
            return self.min_heap[0]
```

```C++ []
class MedianFinder {
    priority_queue<int> lo;                              // 大顶堆
    priority_queue<int, vector<int>, greater<int>> hi;   // 小顶堆

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // 加到大顶堆

        hi.push(lo.top());                               // 平衡
        lo.pop();

        if (lo.size() < hi.size()) {                     // 维护两个堆元素个数
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};
```
#### 复杂度分析
- 时间复杂度：${\mathcal{O}}(log n)$。堆插入和删除需要 ${\mathcal{O}}(log n)$，查找中位数需要 ${\mathcal{O}}(1)$。
- 空间复杂度：${\mathcal{O}}(n)$。

PS：想要一起努力的童鞋们可以关注我的公众号：腐烂的橘子，致力于摆脱算法的抽象思维，彻底搞懂算法，同时公众号还会发布面试中的高频知识点，一起努力吧！😋