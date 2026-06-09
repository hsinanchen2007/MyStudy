反转法，五行代码搞定。
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size())
            k = k%nums.size();
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
```

