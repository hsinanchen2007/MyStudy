利用set，遍历数组插入，若能查找直接返回true，否则插入，直到最后从未查找成功则说明不存在重复，返回false

代码：
```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            if(s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
```
