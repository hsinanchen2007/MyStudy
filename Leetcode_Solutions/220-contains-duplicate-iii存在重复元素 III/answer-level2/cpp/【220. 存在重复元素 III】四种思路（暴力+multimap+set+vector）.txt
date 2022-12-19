## 思路一：暴力（超时）
### 代码
```
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {        
        if (nums.empty()) return false;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j - i > k) break;
                if (abs((long)nums[i] - (long)nums[j]) <= t) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

## 思路二：multimap
### 代码
```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {        
        if (nums.empty()) return false;
        multimap<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp.insert({nums[i], i});
        }
        for (auto it = mp.cbegin(); it != mp.cend(); ++it) {            
            auto iter = it;
            for (++iter; iter != mp.cend(); ++iter) {
                if (abs((long)iter->first - (long)it->first) > t) break;
                if (abs(iter->second - it->second) <= k) return true;
            }
        }
        return false;
    }
};
```

## 思路三：set（推荐）
通过set维护一个固定大小滑动窗口。
**注意：long型防溢出**
### 代码
时间复杂度：O(nlog(min(n,k)))
空间复杂度：O(min(n,k))
```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {        
        if (nums.empty()) return false;
        set<long> st;
        for (int i = 0; i < nums.size(); ++i) {                        
            auto s = st.lower_bound((long)nums[i] - t);//找大于等于num[i] - t的数
            if (s != st.end() && *s <= (long)nums[i] + t) return true;//如果找到并且这个数小于等于nums[i] + t，返回true
            st.insert(nums[i]);
            if (st.size() > k) {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};
```

## 思路四：利用vector
### 代码
```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int, int>> dup;
        for (int i = 0; i < nums.size(); ++i) {
            dup.push_back({nums[i], i});
        }
        sort(dup.begin(), dup.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (dup[j].first <= dup[i].first + t) {//防溢出
                    if (abs(dup[i].second - dup[j].second) <= k) return true;
                } else {
                    break;
                }
            }
        }
        return false;
    }
};
```




