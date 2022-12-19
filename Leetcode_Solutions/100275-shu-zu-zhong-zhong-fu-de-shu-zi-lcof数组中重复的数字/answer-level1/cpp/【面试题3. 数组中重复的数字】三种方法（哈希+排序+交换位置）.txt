## 思路一：哈希表
初始化哈希表大小为数组元素大小，初始值为-1（因为数组中所有元素大于0）。
遍历数组每个数字n，如果哈希值为0，表示该数字已经存在，直接返回；否则，更新数字n对应位置哈希值为0表示已经存在。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> hash(nums.size(), -1);
        for (auto n : nums) {
            if (hash[n] == 0) return n;
            ++hash[n];
        }
        return -1;
    }
};
```

## 思路二：排序后查找
排序后，如果存在相邻两个数字相等则返回。

### 代码
时间复杂度：O(nlogn)
空间复杂度：O(1)
```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] ==  nums[i - 1]) return nums[i];
        }
        return -1;
    }
};
```

## 思路三：交换位置
对每个数组下标位置 i，判断是否等于nums[i]
- 如果下标位置 i 不等于 nums[i]，则nums[i]实际应该放在nums[nums[i]]位置上
  - 如果nums[i] 等于 nums[nums[i]]，则找到重复元素；
  - 否则，交换nums[i] 和 nums[nums[i]]，即将nums[i]放在了正确的位置。
- 如果相等，则判断下一个位置。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
```

