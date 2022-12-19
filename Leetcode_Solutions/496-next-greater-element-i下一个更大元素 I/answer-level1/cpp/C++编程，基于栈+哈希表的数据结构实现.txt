### 解题思路
解题思路和官方题解一样，用C++实现了一遍。
时间复杂度：O(M+N)，M和N分别是数组nums1和nums2的长度
空间复杂度：O(N)

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        stack<int> data;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!data.empty() && data.top() < nums2[i]) {
                hashmap[data.top()] = nums2[i];
                data.pop();
            }
            data.push(nums2[i]);
        }
        while (!data.empty()) {
            hashmap[data.top()] = -1;
            data.pop();
        }

        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            res.push_back(hashmap[nums1[i]]);
        }
        return res;
    }
};
```