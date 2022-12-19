```
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int count, val;
        for(int i = 0; i < nums.size()/2; ++i)
        {
        	count = nums[2*i];
        	val = nums[2*i+1];
        	while(count--)
        		ans.push_back(val);
        }
        return ans;
    }
};
```
