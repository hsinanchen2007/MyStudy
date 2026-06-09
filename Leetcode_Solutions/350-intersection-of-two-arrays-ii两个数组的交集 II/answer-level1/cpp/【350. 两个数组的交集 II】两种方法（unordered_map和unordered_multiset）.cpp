## 思路一：基于无序map
### 代码
```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ms;
        vector<int> res;
        for (auto n : nums1) {
            ++ms[n];
        }
        for (auto n : nums2) {            
            if (ms[n]-- > 0) {
                res.push_back(n);                
            }
        }
        return res;
    }
};
```

## 思路二：基于无序multiset
unordered_multiset类型erase()会删除所有相同元素，所有这里使用迭代器保证只删除一个元素。
### 代码
```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> ms;
        vector<int> res;
        for (auto n : nums1) {
            ms.insert(n);
        }
        for (auto n : nums2) {
            auto it = ms.find(n);
            if (it != ms.end()) {
                res.push_back(n);
                ms.erase(it);
            }
        }
        return res;
    }
};
```



