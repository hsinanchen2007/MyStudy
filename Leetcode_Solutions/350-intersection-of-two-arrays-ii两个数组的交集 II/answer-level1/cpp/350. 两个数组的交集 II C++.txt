### 解题思路
1.使用hash_map对数组nums1中的每一个元素进行计数记录。
2.在遍历nums2，找到存在与hash_map中存在的元素并按照计数器个数压入nums1中，从头压入。
3.若nums2的大小小于nums1则调换位置递归。

### 代码

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }
    unordered_map<int, int> m;
    for (int n : nums1) {
        m[n]++;
    }
    int k = 0;
    for (int n : nums2) {
        unordered_map<int,int>::iterator it = m.find(n);
        if (it != end(m) && --it->second >= 0) {
            nums1[k++] = n;
        }
    }
    return vector<int> (begin(nums1), begin(nums1) + k);
    }
};
```