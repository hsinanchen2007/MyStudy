### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hash;
        for(int cur:nums){
            if(hash.count(cur)>0) hash.erase(cur);
            else hash.insert(cur);
        }
        auto it = hash.begin();
        return *it;

    }
};
```