### 解题思路
看到题想起之前看c++ primer 上有个类似的例题，果然用函数就能解决。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
       auto end_unique=unique(nums.begin(),nums.end());
       nums.erase(end_unique,nums.end());
       int j=nums.size();
       return j;
    }
};
```