### 思路一：优先队列

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](int left, int right) { return left > right; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (const auto &n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
```
### 另一种写法
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {        
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};
```

### 思路二：分治
利用快排思想。

### 代码
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {        
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            else if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }

    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
```

