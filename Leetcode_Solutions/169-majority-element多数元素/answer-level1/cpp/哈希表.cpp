### 解题思路
null

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> nummap;
        for(auto i : nums)
        {
            nummap[i]++;
        }
        int res;
        for(auto i : nummap)
        {
            if(i.second>((nums.size()/2)))
            {
                res = i.first;
            }
        }
        return res;
    }
};
```