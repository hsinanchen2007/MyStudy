### 解题思路
方法一：堆
思路和算法

我们用一个大根堆实时维护数组的前 k 小值。
首先将所有数插入大根堆中，维护一个长度为k的大根堆，堆长度大于k,就把堆顶的数弹出。最后将大根堆里的数存入数组返回即可。在下面的代码中，由于 C++ 语言中的堆（即优先队列）为大根堆，我们可以这么做。而 Python 语言中的堆为小根堆，因此我们要对数组中所有的数取其相反数，才能使用小根堆维护前 k 小值。


### 代码

```python3 []
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        heap, res = [], []
        for x in arr:
            heapq.heappush(heap, -x) # Python 小根堆加负号，变成大根堆
            if len(heap) > k: heapq.heappop(heap)
        while len(heap): 
            res.append(-heap[0])
            heapq.heappop(heap)
        return res
```
```c++ []
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int> heap;   //大根堆
        for ( auto x : arr){
            heap.push(x);
            if (heap.size() > k) heap.pop();
        }
        while (heap.size()) res.push_back(heap.top()), heap.pop();
        return res;
    }
};
```

复杂度分析

时间复杂度：O(nlogk)，其中 n 是数组 arr 的长度。由于大根堆实时维护前 k 小值，所以插入删除都是O(logk) 的时间复杂度，最坏情况下数组里 n 个数都会插入，所以一共需要 O(nlogk) 的时间复杂度。

空间复杂度：O(k)，因为大根堆里最多 k 个数。


## 方法二:快排分区

```python3 []
class Solution:
    def partition(self, nums, l, r):
        pivot = nums[l]
        while l < r:
            while l < r and pivot <= nums[r]:
                r -= 1
            nums[l] = nums[r]
            while l < r and nums[l] <= pivot:
                l += 1
            nums[r] = nums[l]
        nums[l] = pivot
        return l 

    def random_partition(self, nums, l, r):
        import random
        i = random.randint(l, r) # l r内生成一个随机数
        nums[r], nums[i] = nums[i], nums[r] #交换
        return self.partition(nums, l, r) 

    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0: return list()
        l, r = 0, len(arr)-1
        idx = self.random_partition(arr, l, r)
        while idx != k - 1:
            if idx < k-1:
                l = idx+1
                idx = self.partition(arr, l, r)
            if idx > k-1:
                r = idx-1
                idx = self.partition(arr, l, r)
        return arr[:k]

```

复杂度分析

时间复杂度：期望为O(n) ，由于证明过程很繁琐，所以不再这里展开讲。具体证明可以参考《算法导论》第 9 章第 2 小节。

最坏情况下的时间复杂度为 O(n^2)。情况最差时，每次的划分点都是最大值或最小值，一共需要划分n−1 次，而一次划分需要线性的时间复杂度，所以最坏情况下时间复杂度为 O(n^2)O(n 
2
 )。

空间复杂度：期望为 O(logn)，递归调用的期望深度为 O(logn)，每层需要的空间为 O(1)，只有常数个变量。

最坏情况下的空间复杂度为 O(n)。最坏情况下需要划分 n 次，即 randomized_selected 函数递归调用最深 n−1 层，而每层由于需要 O(1) 的空间，所以一共需要 O(n) 的空间复杂度。