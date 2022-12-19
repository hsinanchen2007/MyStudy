![1.png](https://pic.leetcode-cn.com/bb7087ab2efca6f1afcca54845c7a9913aba96ef4c20e0fc55e352281403479b-1.png)

### 代码
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> cache(nums1.begin(), nums1.end());

        for (auto num2 : nums2) 
            if (cache.erase(num2))res.push_back(num2);    

        return res;
    }
};
```