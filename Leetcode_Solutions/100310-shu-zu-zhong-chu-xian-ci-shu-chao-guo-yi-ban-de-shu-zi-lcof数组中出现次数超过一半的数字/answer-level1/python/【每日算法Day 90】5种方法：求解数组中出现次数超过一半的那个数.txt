## 题解
### 哈希表
这个方法最简单，用哈希表记录每个数字出现的次数，最后看哪个数字次数超过一半就行了。

时间复杂度 $O(n)$ ，空间复杂度 $O(n)$ 。

### 排序
对数组从小到大进行排序，那么众数一定在 `nums[n/2]` 处。为什么呢？

因为排序后相同的数都连续了，所以众数最左端的极限情况就是从下标 `0` 开始往后排，那么因为超过了一半，所以尾部下标一定会超过 `n/2` 。而最右端的极限情况就是从下标 `n-1` 往前排，因为超过了一半，所以头部下标也会在 `n/2` 之前。

综上，众数所在的区间一定会包含下标 `n/2` 。

时间复杂度 $O(n \log n)$ ，空间复杂度 $O(\log n)$ 。

### 随机采样
其实我第一个想到的方法反而是这个反常规的随机采样方法。因为众数超过了一半，所以采样大概率会采到这个众数。

那么我们随机采样一个数，然后遍历一遍数组看它的个数。如果个数超过了一半就是它了，否则继续采样，直到采到众数。

平均时间复杂度 $O(n)$ ，空间复杂度 $O(1)$ 。

### 分治
如果把区间 `[0, n-1]` 平均分成两半，那么我们可以证明，原来的众数在某一半区间里依然是众数。

为什么呢？反证法，假设两半区间的众数都不是原来的众数，那么在左半区间原来的众数一定小于一半，右半区间也是的。加起来之后总数一定小于一半的，和条件是矛盾的。

所以我们递归求解两半区间的众数，然后看哪个数出现次数较多，众数就是它了。

时间复杂度 $O(n \log n)$ ，空间复杂度 $O(\log n)$ 。

### 摩尔投票
这个方法我一开始也想到了，但是没有想到这竟然有理论解释，而且是大名鼎鼎的摩尔投票算法。

它的主要步骤是这样的：
* 初始化两个变量， `cand` 表示候选人，`cnt` 表示赞同它的票数。
* 如果 `cnt = 0`，那么 `cand` 就设置为当前的数字。
* 如果 `cand` 等于当前数字，那么票数 `cnt` 加一，否则票数减一。
* 最后 `cand` 就是得票超过一半的众数。

严格证明比较复杂，是一篇论文，这里说个比较好理解的思路：
* 如果当前候选人是众数，那么其他的众数会支持自己，其他的数反对自己。但是因为众数超过了一半，所以众数最后一定会当选。
* 如果当前候选人不是众数，那么就惨了，其他的数和众数全都会反对他。那反对票远远超过一半了，肯定会下台，然后换候选人。
* 上面两种情况会在 `cnt = 0` 的时刻进行转换，也就是换候选人。

时间复杂度 $O(n)$ ，空间复杂度 $O(1)$ 。

## 代码
### 哈希表（c++）
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto x : nums) mp[x]++;
        for (auto [k, v] : mp) {
            if (v > n/2) return k;
        }
        return -1;
    }
};
```

### 排序（c++）
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};
```

### 随机采样（c++）
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        while (1) {
            int idx = rand() % n;
            int cnt = 0;
            for (auto x : nums) {
                if (x == nums[idx]) cnt++;
            }
            if (cnt > n/2) return nums[idx];
        }
        return -1;
    }
};
```

### 分治（c++）
```cpp
class Solution {
public:
    int numCount(vector<int>& nums, int x, int l, int r) {
        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            if (nums[i] == x) cnt++;
        }
        return cnt;
    }

    int findMajority(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int m = l+(r-l)/2;
        int ml = findMajority(nums, l, m);
        int mr = findMajority(nums, m+1, r);
        if (ml == mr) return ml;
        int cl = numCount(nums, ml, l, r);
        int cr = numCount(nums, mr, l, r);
        return cl < cr ? mr : ml;
    }

    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return findMajority(nums, 0, n-1);
    }
};
```

### 摩尔投票（c++）
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0, cnt = 0;
        for (auto x : nums) {
            if (!cnt) cand = x;
            if (x == cand) cnt++;
            else cnt--;
        }
        return cand;
    }
};
```

### 哈希表（python）
```python
class Solution:
    def majorityElement(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
```

### 排序（python）
```python
class Solution:
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums)//2]
```

### 随机采样（python）
```python
import random

class Solution:
    def majorityElement(self, nums):
        majority_count = len(nums)//2
        while True:
            candidate = random.choice(nums)
            if sum(1 for elem in nums if elem == candidate) > majority_count:
                return candidate
```

### 分治（python）
```python
class Solution:
    def majorityElement(self, nums, lo=0, hi=None):
        def majority_element_rec(lo, hi):
            if lo == hi:
                return nums[lo]
            mid = (hi-lo)//2+lo
            left = majority_element_rec(lo, mid)
            right = majority_element_rec(mid+1, hi)
            if left == right:
                return left
            left_count = sum(1 for i in range(lo, hi+1) if nums[i] == left)
            right_count = sum(1 for i in range(lo, hi+1) if nums[i] == right)
            return left if left_count > right_count else right
        return majority_element_rec(0, len(nums)-1)
```

### 摩尔投票（python）
```python
class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None
        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)
        return candidate
```

> 关注公众号【算法码上来】，每日算法干货马上就来！
![宣传图片.jpg](https://pic.leetcode-cn.com/14fbef421efcd8960829f6bc3afc8c5d8422e49479db4ca7a3ec1c49cdc7c66d-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)
