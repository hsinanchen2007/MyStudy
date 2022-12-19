
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

         return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size(); 
         //如果原数组的大小>集合的大小，则说明存在重复元素
    }
};


```