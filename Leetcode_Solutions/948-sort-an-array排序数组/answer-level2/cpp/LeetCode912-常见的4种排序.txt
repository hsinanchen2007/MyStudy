### 快速排序
```cpp
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int x = nums[l+r>>1];  // l+r>>1等价于 (l+r)/2
        int i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < x);
            do j--; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        return j;
    }
    
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot);
        quickSort(nums, pivot + 1, r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};
```

### 归并排序
```cpp
class Solution {
public:
    vector<int> t;  // 临时排序的数的，然后在合并回原数组
    
    void merge(vector<int>& nums, int l, int mid, int r) {
        int i = l, j = mid + 1;
        int len = 0;
        
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) t[len++] = nums[i++];
            else t[len++] = nums[j++];
        }
        while (i <= mid) t[len++] = nums[i++];
        while (j <= r) t[len++] = nums[j++];
        
        for (int i = 0; i < len; i++) {
            nums[l+i] = t[i];
        }
    }
    
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + r >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        t = vector<int>(n);
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};
```

### 堆排序
```cpp
class Solution {
private:
    inline int getFa(int i) {
        return (i + 1) / 2 - 1;
    }
    
    inline int getLeft(int i) {
        return 2 * i + 1;
    } 
    
    inline int getRight(int i) {
        return 2 * i + 2;
    }
    
    void down(vector<int>& nums, int i, int tail) {
        while (getLeft(i) < tail) {
            int t = nums[getLeft(i)] > nums[i] ? getLeft(i) : i;
            if (getRight(i) < tail) t = nums[getRight(i)] > nums[t] ? getRight(i) : t;
            if (t == i) break;
            swap(nums[t], nums[i]);
            i = t;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2; i >= 0; i--) {
            down(nums, i, n - 1);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            down(nums, 0, i);
        }
        return nums;
    }
};
```

### 计数排序
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return {}; // 空数组直接返回
        // 最大值 最小值
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int n = high - low + 1; // 桶的大小(节省空间,若最小值大于0,则最小值前面的空间被浪费)
        vector<int> buckets(n);
        for (auto x : nums) ++buckets[x - low]; // 每个桶下标 + 最小值 = 原数 , 桶值代表有多少个相同的数
        vector<int> res;
        // 遍历每个桶,由小到大直接写入结果
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < buckets[i]; ++j) {
                res.push_back(i + low);
            }
        }
        return res;
    }
};
```