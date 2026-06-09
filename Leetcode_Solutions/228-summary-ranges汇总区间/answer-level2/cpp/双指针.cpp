```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int n=nums.size(),i=0;
        while(i<n){
            int j=i+1,k=1;
            while(j<n&&(long)nums[j]-nums[i]==k){
                k++;
                j++;
            }
            if(j-i==1){
                res.push_back(to_string(nums[i]));
            }else{
                res.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
            }
            i=j;
        }
        return res;
    }
};
```