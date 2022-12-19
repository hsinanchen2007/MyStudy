### 解题思路
vector的简单应用，没有什么可说的，直接看代码。

### 代码

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i+=2)
            res.insert(res.end(),nums[i],nums[i+1]);
        return res;
    }
};
```