### 解题思路
辅助数组
先遍历nums1 出现过的辅助数组设为1；
后遍历nums2 辅助数组为1 的放入res；

### 代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int mp[10010]={0};
    vector<int> res;
    for(int i = 0 ; i < nums1.size(); i++){
        if(mp[nums1[i]] == 0) mp[nums1[i]]++;
    }
    for(int i = 0; i < nums2.size(); i++){
        if(mp[nums2[i]] > 0) {
            mp[nums2[i]]--;
            res.push_back(nums2[i]);
            }

    }
    return res;
    }
};
```