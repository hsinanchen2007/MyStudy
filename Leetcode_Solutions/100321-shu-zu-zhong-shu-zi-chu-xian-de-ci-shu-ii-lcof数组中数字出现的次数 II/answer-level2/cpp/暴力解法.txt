### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto n : nums)
            umap[n]++;
        for(auto n : nums)
        {
            if(umap[n] == 1)return n;
        }
        return -1;
    }
};
```