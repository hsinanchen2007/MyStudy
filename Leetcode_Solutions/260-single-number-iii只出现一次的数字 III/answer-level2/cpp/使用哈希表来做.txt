### 解题思路
这里直接使用哈希表来判断是否之前出现过。
除了unordered_set之外，也可以使用map来做。
不过时间复杂度可能就会出问题了，还是需要位运算来做。
位运算的做法，随后再补
### 代码

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> res;
        for(int i=0;i<nums.size();i++){
            if(!res.insert(nums[i]).second){
                res.erase(nums[i]);
            }
        }
        //直接将unordered_set转化为vector
        vector<int> result(res.begin(),res.end());
        return result;
    }
};
```