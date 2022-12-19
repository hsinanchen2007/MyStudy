```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=0;
        for(int i=0, j=0; i<nums.size(); i=j){
            for(j=i+1; j<nums.size() && nums[i]==nums[j]; ++j);
            for(int k=0; k<2 && i+k<j; nums[len++]=nums[i+k++]);
        }
        return len;
    }
};
```
