```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::stable_sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> t(3);
        int l,r;
        for(int i=0;i<n-2;i++)
        {
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            l = i + 1;
            r = n - 1;
            
            while(l < r){
                while(l > i+1 && l < r && nums[l] == nums[l-1]){
                    l++;
                }
                while(r < n-2 &&  l < r && nums[r] == nums[r+1]){
                    r--;
                }
                if(l < r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum < 0){
                        l++;
                    }
                    else if(sum > 0 ){
                        r--;
                    }
                    else{
                        t[0]=nums[i];
                        t[1]=nums[l];
                        t[2]=nums[r];
                        res.push_back(t);
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
```
