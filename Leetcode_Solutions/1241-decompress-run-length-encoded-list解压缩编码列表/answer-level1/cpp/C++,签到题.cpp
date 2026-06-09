```
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i+=2){
            int k=nums[i];
            int num=nums[i+1];
            while(k--){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
```
