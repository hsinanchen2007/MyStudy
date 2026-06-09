## 思路一：哈希表
统计每个数出现次数，然后查找出现次数超过一半的数。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> ump;
        for (auto n : nums) {
            if (ump.count(n) == 0) ump.insert({n, 1});
            else ++ump[n];
        }
        for (auto it = ump.begin(); it != ump.end(); ++it) {
            if (it->second > size / 2) return it->first;
        }
        return -1;
    }
};
```

## 思路二：投票
初始假设第一个数出现次数最大，然后遍历每个数，如果遇到相同，则次数加1，否则次数减1，如果次数大于一半0，则直接返回，如果次数为0，则重置当前数为出现次数最多数。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int res = nums[0], cnt = 1;
        for (int i = 1; i < size; ++i) {
            if (nums[i] == res) ++cnt;
            else --cnt;
            if (cnt > size / 2) return res;
            if (cnt == 0) {                
                res = nums[i];
                cnt = 1;
            }            
        }
        return res;
    }
};
```
