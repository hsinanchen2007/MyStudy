### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
  for (auto nu1 : nums1) {
    int curr_res = -1;
    for (size_t j = nums2.size() - 1; j >= 0; --j) {
      if (nu1 == nums2[j]) {
        break;
      }
      if (nu1 < nums2[j]) {
        curr_res = nums2[j];
      }
    }
    result.push_back(curr_res);
  }
  return result;
}
};
```