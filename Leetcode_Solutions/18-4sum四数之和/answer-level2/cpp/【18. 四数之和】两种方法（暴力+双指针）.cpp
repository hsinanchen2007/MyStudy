### 思路一：暴力
利用set去重

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {        
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());        
        unordered_map<int, int> ump;
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); ++i) {
            ump[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    int t = target - nums[i] - nums[j] - nums[k];
                    if (ump[t] > k) {
                        vector<int> out = {nums[i], nums[j], nums[k], t};
                        st.insert(out);
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
```
### 另一种写法
手动去重
```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {              
        if (nums.empty()) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());        
        unordered_map<int, int> ump;        
        for (int i = 0; i < nums.size(); ++i) {
            ump[nums[i]] = i;
        }
        int size = nums.size();
        for (int i = 0; i < size - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;//去重
            for (int j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1; k < size - 1; ++k) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    int t = target - nums[i] - nums[j] - nums[k];
                    if (ump[t] > k) {
                        vector<int> out = {nums[i], nums[j], nums[k], t};
                        res.push_back(out);
                    }
                }
            }
        }
        return res;
    }
};
```

### 思路二：双指针

### 代码
```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {              
        if (nums.empty()) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());        
        int size = nums.size();
        for (int i = 0; i < size - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = size - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(out);                        
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left, --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
```

### 优化时间复杂度
提前判断当前最小和、最大和是否越界。
```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {              
        if (nums.empty()) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());        
        int size = nums.size();
        for (int i = 0; i < size - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int min1 = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (min1 > target) break;
            int max1 = nums[i] + nums[size - 1] + nums[size - 2] + nums[size - 3];
            if (max1 < target) continue;
            for (int j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                min1 = nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (min1 > target) break;
                max1 = nums[i] + nums[j] + nums[size - 1] + nums[size - 2];
                if (max1 < target) continue;
                int left = j + 1, right = size - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(out);                        
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left, --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
```



