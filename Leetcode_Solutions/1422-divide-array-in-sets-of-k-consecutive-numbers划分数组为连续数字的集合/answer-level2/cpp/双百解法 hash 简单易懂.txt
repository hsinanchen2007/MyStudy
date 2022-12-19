```
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0)
            return false;
        sort(nums.begin(), nums.end());
        map<int, int> hash;
        for(auto s:nums) hash[s]++;
        int size = nums.size() / k;
        for(int i = 0; i < size; i ++){
            int index = 0;
            while(hash[nums[index]] == 0) index++;
            int start = nums[index];
            for(int j = start; j < start + k; j ++){
                if(hash[j] == 0)
                    return false;
                else
                    hash[j]--;
            }
        }
        return true;
        
    }
};
```
