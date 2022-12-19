```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int,int> m;
        for(int num:nums) {
            if(++m[num] > n) return num;
        }
        return -1;
    }
};
```
