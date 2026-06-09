### 思路一：哈希表
不满足空间复杂度

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        int size = nums.size();
        unordered_map<int, int> ump;
        for (int i = 0; i < size; ++i) {
            ump[nums[i]] = i;
        }
        for (int i = 1; i <= size; ++i) {
            if (ump.count(i) == 0) return i;
        }
        return size + 1;
    }
};
```

### 思路二：调换位置

### 代码
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size =  nums.size();
        for (int i = 0; i < size; ++i) {
            while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < size; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return size + 1;
    }
};
```
