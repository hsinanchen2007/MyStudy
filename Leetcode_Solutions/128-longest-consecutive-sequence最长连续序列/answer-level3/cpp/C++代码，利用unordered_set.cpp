```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> myset(nums.begin(), nums.end());
        int res = 0;
        
        for(auto num : nums){
            if(myset.count(num-1)==0){
                int x = num + 1;
                while(myset.count(x)){
                    x ++;
                }
                res = max(res, x-num);
            }
        }
        return res;
    }
};
```

* 执行用时 :16 ms, 在所有 C++ 提交中击败了76.66%的用户
* 内存消耗 :10 MB, 在所有 C++ 提交中击败了59.76%的用户