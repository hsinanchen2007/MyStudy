### 思路
- 用内置函数`unordered_set`,若还不存在该值就插入到set内，
- 若count>0 返回true
```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> hashset;
        for(auto i : nums){
            if(hashset.count(i) > 0){
                return true;
            }
            else{
                hashset.insert(i);
            }
        }
        return false;
    }
};
```
