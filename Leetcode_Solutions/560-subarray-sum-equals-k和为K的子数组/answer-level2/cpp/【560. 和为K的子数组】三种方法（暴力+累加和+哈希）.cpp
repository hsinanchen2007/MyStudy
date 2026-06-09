### 思路一：暴力法


### 代码

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size(), res = 0;
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j < size; ++j) {
                sum += nums[j];
                if (sum == k) {
                    ++res;                    
                } 
            }
        }
        return res;
    }
};
```

### 思路二：累加和

### 代码
```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size(), res = 0;
        vector<int> sums = nums;
        for (int i = 1; i < size; ++i) {
            sums[i] += sums[i - 1];
        }
        for (int i = 0; i < size; ++i) {
            if (sums[i] == k) ++res;
            for (int j = i - 1; j >= 0; --j) {
                if (sums[i] - sums[j] == k) ++res;
            }
        }
        return res;
    }
};
```

### 思路三：哈希表（最优解）
将累加和存在哈希表中（可能存在多个累加和相同），如果当前累加和sum[j] - k = sum[i]（i < j）存在哈希表，则 [i + 1, j] 范围内连续子数组和为k，满足条件。

### 代码
```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> ump{{0, 1}};
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            res += ump[sum - k];
            ++ump[sum];
        }
        return res;
    }
};
```

