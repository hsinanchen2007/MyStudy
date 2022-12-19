### 解题思路
1. 对数组分别进行排序
2. 查找至交集开始处，比对结果集中是否插入当前过当前元素，已插入则丢弃，未插入则保存
### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return vector<int>();
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        if (nums1.back() < nums2.front() 
            || nums1.front() > nums2.back()) {
            return res;
        }

        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 > *it2) {
                ++it2;
                continue;
            } 
            if (*it1 < *it2) {
                ++it1;
                continue;
            }

            if (res.empty() || res.back() != *it1) {
                res.push_back(*it1);
            }
            ++it1;
            ++it2;
        }
        return res;
    }
};
```