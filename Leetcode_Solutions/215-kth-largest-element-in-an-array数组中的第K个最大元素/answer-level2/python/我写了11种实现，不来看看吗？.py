> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/447b08aefc6f64ddaf4c6b7e675bd949559a0f436db243c6fc5a026b0a685fb2-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)


## 题解
### 排序
对数组从大到小排序，取第 $k$ 个元素。

或者从小到大排序，取第 $n-k+1$ 个元素。

### 小根堆+库函数
`c++` 自带 `priority_queue<int>` ，可以实现小根堆。

`python` 自带 `heapq` ，可以实现小根堆，同时还自带 `nlargest` 函数可以直接求出前 $k$ 大元素。

然后维护一个大小为 $k$ 的小根堆，保存最大的 $k$ 个数，堆顶就是第 $k$ 大的数。新元素入堆，如果堆中元素个数大于 $k$ ，就将堆顶元素出堆。

### 大根堆+库函数

`c++` 自带 `priority_queue<int, vector<int>, greater<int>>` ，可以实现大根堆。

`python` 没有大根堆实现。

然后维护一个大小为 $n-k+1$ 的大根堆，保存最小的 $n-k+1$ 个数，堆顶就是第 $n-k+1$ 小的数，即第 $k$ 大的数。新元素入堆，如果堆中元素个数大于 $n-k+1$ ，就将堆顶元素出堆。

### 小根堆+手写
利用原地算法，直接将原数组当作一个小根堆。

首先对前 $k$ 个元素建立初始堆。然后遍历后面的元素，如果大于堆顶元素的话，就和堆顶元素交换位置，并调整堆。

小根堆大小始终为 $k$ 。

### 大根堆+手写
利用原地算法，直接将原数组当作一个大根堆。

首先对前 $n-k+1$ 个元素建立初始堆。然后遍历后面的元素，如果小于堆顶元素的话，就和堆顶元素交换位置，并调整堆。

大根堆大小始终为 $n-k+1$ 。

### 快速选择
思想类似于快速排序，首先随机选取一个元素 $p$，然后将区间内元素比 $p$ 小的都放在 $p$ 左边，比 $p$ 大的都放在 $p$ 右边。

然后看 $p$ 的下标 $i$，如果 $i+1 = n-k+1$，那就说明 $p$ 就是第 $n-k+1$ 小（第 $k$ 大）的元素，直接返回即可。否则如果 $i+1 < n-k+1$，那就说明第 $k$ 大元素在 $p$ 的右边区间内，递归寻找即可。否则就在左边区间，递归寻找。
## 代码
### 排序（c++）
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};
```

### 小根堆+STL优先队列（c++）
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> Q;
        for (auto x : nums) {
            Q.push(x);
            while (Q.size() > k) Q.pop();
        }
        return Q.top();
    }
};
```

### 大根堆+STL优先队列（c++）
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> Q;
        for (auto x : nums) {
            Q.push(x);
            while (Q.size() > nums.size()-k+1) Q.pop();
        }
        return Q.top();
    }
};
```

### 小根堆+手写（c++）
```cpp
class Solution {
public:
    void adjust(vector<int>& nums, int p, int s) {
        while (2*p+1 < s) {
            int c1 = 2*p+1;
            int c2 = 2*p+2;
            int c = (c2<s && nums[c2]<nums[c1]) ? c2 : c1;
            if (nums[c] < nums[p]) swap(nums[c], nums[p]);
            else break;
            p = c;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = k/2-1; i >= 0; --i) {
            adjust(nums, i, k);
        }
        for (int i = k; i < n; ++i) {
            if (nums[0] >= nums[i]) continue;
            swap(nums[0], nums[i]);
            adjust(nums, 0, k);
        }
        return nums[0];
    }
};
```

### 大根堆+手写（c++）
```cpp
class Solution {
public:
    void adjust(vector<int>& nums, int p, int s) {
        while (2*p+1 < s) {
            int c1 = 2*p+1;
            int c2 = 2*p+2;
            int c = (c2<s && nums[c2]>nums[c1]) ? c2 : c1;
            if (nums[c] > nums[p]) swap(nums[c], nums[p]);
            else break;
            p = c;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = (n-k+1)/2-1; i >= 0; --i) {
            adjust(nums, i, (n-k+1));
        }
        for (int i = (n-k+1); i < n; ++i) {
            if (nums[0] <= nums[i]) continue;
            swap(nums[0], nums[i]);
            adjust(nums, 0, (n-k+1));
        }
        return nums[0];
    }
};
```

### 快速选择（c++）
```cpp
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int p = l+rand()%(r-l+1), m = l;
        swap(nums[p], nums[r]);
        for (int i = l; i < r; ++i) {
            if (nums[i] < nums[r]) {
                swap(nums[i], nums[m++]);
            }
        }
        swap(nums[m], nums[r]);
        return m;
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int m = partition(nums, l, r);
        if (k == m+1) return nums[m];
        if (k < m+1) return quickSelect(nums, l, m-1, k);
        return quickSelect(nums, m+1, r, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        srand((int)time(0));
        return quickSelect(nums, 0, n-1, n-k+1);
    }
};
```


### 排序（python）
```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)
        return nums[k-1]
```

### 小根堆+heapq（python）
```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]
```

### 小根堆+手写（python）
```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def adjust(nums, p, s):
            while 2*p+1 < s:
                c1, c2 = 2*p+1, 2*p+2
                c = c2 if (c2<s and nums[c2]<nums[c1]) else c1
                if nums[c] < nums[p]:
                    nums[c], nums[p] = nums[p], nums[c]
                else:
                    break
                p = c

        n = len(nums)
        for i in range(k//2-1, -1, -1):
            adjust(nums, i, k)
        for i in range(k, n):
            if nums[0] >= nums[i]: continue
            nums[0], nums[i] = nums[i], nums[0]
            adjust(nums, 0, k)
        return nums[0]
```

### 大根堆+手写（python）
```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def adjust(nums, p, s):
            while 2*p+1 < s:
                c1, c2 = 2*p+1, 2*p+2
                c = c2 if (c2<s and nums[c2]>nums[c1]) else c1
                if nums[c] > nums[p]:
                    nums[c], nums[p] = nums[p], nums[c]
                else:
                    break
                p = c

        n = len(nums)
        for i in range((n-k+1)//2-1, -1, -1):
            adjust(nums, i, (n-k+1))
        for i in range((n-k+1), n):
            if nums[0] <= nums[i]: continue
            nums[0], nums[i] = nums[i], nums[0]
            adjust(nums, 0, (n-k+1))
        return nums[0]
```

### 快速选择（python）
```python
import random

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(nums, l, r):
            p, m = l+random.randint(0, r-l), l
            nums[p], nums[r] = nums[r], nums[p]
            for i in range(l, r):
                if nums[i] < nums[r]:
                    nums[m], nums[i] = nums[i], nums[m]
                    m += 1
            nums[m], nums[r] = nums[r], nums[m]
            return m
        
        def quickSelect(nums, l, r, k):
            if l == r: return nums[l]
            m = partition(nums, l, r)
            if k == m+1: return nums[m]
            if k < m+1: return quickSelect(nums, l, m-1, k)
            return quickSelect(nums, m+1, r, k)

        n = len(nums)
        return quickSelect(nums, 0, n-1, n-k+1)
```