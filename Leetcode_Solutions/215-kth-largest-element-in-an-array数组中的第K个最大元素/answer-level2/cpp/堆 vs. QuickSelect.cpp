### 解题思路一

维护一个容量为K的最小堆，因为有N-K个比堆顶元素小的，有K-1个比堆顶元素大的，所以堆顶元素是第K大。时间复杂度O(N * log K).

### 代码一

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;    // 最小堆
        int i = 0;
        for(int x: nums) {
            heap.push(x);
            i++;
            if(i > k)
                heap.pop();
        }
        return heap.top();
    }
};
```

执行用时 :12 ms

### 解题思路二

QuickSelect

### 代码二

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return QuickSelect(nums, 0, n-1, k);
    }
    
    int QuickSelect(vector<int>& nums, int left, int right, int k) {
        if(left == right)
            return nums[left];
        
        int pivotIndex = Partition(nums, left, right);

        if(left + k - 1 == pivotIndex)
            return nums[pivotIndex];
        else if(left + k - 1 < pivotIndex)
            return QuickSelect(nums, left, pivotIndex - 1, k);
        else
            return QuickSelect(nums, pivotIndex + 1, right, k - pivotIndex + left - 1);
    }
    
    int Partition(vector<int>& nums, int left, int right) {
        // 1. move pivot to end
        int randIdx = left + rand() % (right - left);
        swap(nums[randIdx], nums[right]);
        
        int i = left;
        int pivot = nums[right];
        
        // 2. move all larger elements to the left
        for(int j=left; j<=right-1; j++) {
            if(nums[j] > pivot)                                 // 降序排序
                swap(nums[i++], nums[j]);
        }
        
        // 3. move pivot to its final place
        swap(nums[i], nums[right]);
        
        return i;
    }
};
```

执行用时：8 ms

### 解题思路三

STL

### 代码三

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
        return nums[k-1];
    }
};
```

执行用时：8 ms



