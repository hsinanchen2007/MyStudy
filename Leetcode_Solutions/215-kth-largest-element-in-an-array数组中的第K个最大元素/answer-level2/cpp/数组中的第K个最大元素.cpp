
```
// 215. Kth Largest Element in an Array (Medium)
// 题目描述：找到第 k 大的元素

// 1.sort 排序 
// 时间复杂度 O(NlogN) 空间复杂度 O(1)
int findKthLargest1(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
    return nums[k-1];
}

// 2.堆排序
// 时间复杂度 O(NlogK) 空间复杂度 O(K)
int findKthLargest2(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for (size_t i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
        if (pq.size() > k ) {
            pq.pop();
        }
    }
    return pq.top();
}

// 3.快速选择排序
// 时间复杂度 O(N) 空间复杂度 O(1)
void swapValue(vector<int>& nums, int a, int b) {
    int j = nums[a];
    nums[a] = nums[b];
    nums[b] = j;
}

int partition(vector<int>& nums, int l, int r) {
    int i = l;
    int povit = nums[r];

    for (size_t j = l; j < r; j++) {
        if (nums[j] < povit) {
            swapValue(nums, j, i);
            ++i;
        }
    }

    swapValue(nums, i, r);
    return i;
}

int findKthLargest3(vector<int>& nums, int k) {
    int l = 0;
    int r = nums.size() - 1;
    k = nums.size() - k;
    int val = l;
    while (l <= r) {
        val = partition(nums, l, r);
        if (val > k) {
            r = val - 1;
        } else if (val < k) {
            l = val + 1;
        } else {
            break;
        }
    }
    return nums[val];
}

```
