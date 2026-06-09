## 思路一：遍历
1. 用长的数组依次遍历短的数组
2. 对结果集排序，然后进行去重

### 代码
时间复杂度：O(n*m)
空间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> res;
        if (size1 < size2) {
            for (int i : nums2) {
                for (int j : nums1) {
                    if (i == j) {
                        res.push_back(i);
                        break;
                    }
                }
            }
        } else {
            for (int i : nums1) {
                for (int j : nums2) {
                    if (i == j) {
                        res.push_back(i);
                        break;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        int len = res.size();
        vector<int> ret;
        if (len > 0) {
            ret.push_back(res[0]);
        }        
        for (int i = 1; i < len; i++) {
            if (res[i] == res[i-1]) {
                continue;
            } else {
                ret.push_back(res[i]);
            }
        }
        return ret;
    }
};
```

## 思路二：基于set
1. 构建两个无序set，将其中一个vector添加到set1中（set自动去除重复）。
2. 遍历另一个vector，查看是否在set1中，如果在，则插入set2中。
3. 遍历set2即为交集。

### 代码
时间复杂度：O(n+m)
空间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        unordered_set<int> hash2;
        for (int num : nums1) {
            hash.insert(num);
        }
        for (int num : nums2) {
            if (hash.count(num) > 0) {
                hash2.insert(num);
            }
        }
        vector<int> res;
        unordered_set<int>::iterator it = hash2.begin();
        while (it != hash2.end()) {
            res.push_back(*it);
            it++;
        }
        return res;
    }
};
```

#### 代码优化
```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {                
        vector<int> res;
        unordered_set<int> st;        
        for (auto n : nums1) {
            st.insert(n);
        }
        for (auto n : nums2) {
            if (st.count(n) == 1) {
                res.push_back(n);
                st.erase(n);
            }
        }
        return res;        
    }   
};
```




