## left用来跟踪当前递增序列的首端
```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return 0;
        if(len==1) return 1;
        int left=0, ans=0; //left用来跟踪当前递增序列的首端
        for(int i=1; i<len; i++){
            if(nums[i]<=nums[i-1]){
                ans = max(ans, i-left);
                left = i;
            }
        }
        ans = max(ans, len-left);
        return ans;
    }
};
```