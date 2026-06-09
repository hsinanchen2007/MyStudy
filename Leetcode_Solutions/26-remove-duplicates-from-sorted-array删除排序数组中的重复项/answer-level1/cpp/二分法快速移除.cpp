```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator output = nums.begin();
        vector<int>::iterator it= nums.begin();
        while(it != nums.end()){
            *output++ = *it;
            it = upper_bound(it, nums.end(), *it);
        }
        return distance(nums.begin(), output);
    }
};
```
提交效果：执行用时12ms,内存消耗10MB