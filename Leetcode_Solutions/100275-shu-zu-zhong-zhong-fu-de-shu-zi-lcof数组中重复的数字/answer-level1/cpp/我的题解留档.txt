2020年2月27日，第一次写。
使用C++，用一个hash map，也就是std::unordered_map。
特别注意一点，因为后面return 0; 是必须写的。我第一次没写，报错好多回。

```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> mapping;
        for(int i=0; i<nums.size(); i++){
            mapping[nums[i]] += 1;
            if(mapping[nums[i]] > 1)
                return nums[i];
        }
        return 0;
    }
};
```

