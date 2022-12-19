### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> res;
        for(auto c:nums){
            if(c%2==0) res.push_back(c);
            else res.insert(res.begin(),c);
        }
        return res;
    }
};
```