## 思路一：桶排序
桶号表示距离，每个桶中保存相同距离出现的次数，然后遍历每个桶。
### 代码
时间复杂度：O(n^2)
```c++
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int size = nums.size();        
        vector<int> bucket(1000000);
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                ++bucket[abs(nums[j] - nums[i])];
            }
        }
        for (int i = 0; i < 1000000; ++i) {
            if (bucket[i] >= k) return i;
            k -= bucket[i];
        }
        return -1;
    }
};
```

## 思路二：二分（最优）
对距离进行二分，然后统计小于等于该距离的对数。
### 代码
时间复杂度：O(nlogn)
```c++
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size(), left = 0, right = nums.back() - nums[0];        
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0, start = 0;
            for (int i = 0; i < size; ++i) {
                while (start < size && nums[i] - nums[start] > mid) ++start;
                cnt += i - start;
            }
            if (cnt < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```


