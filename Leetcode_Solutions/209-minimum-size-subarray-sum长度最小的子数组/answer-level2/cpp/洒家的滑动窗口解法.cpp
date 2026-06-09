```

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int>::size_type minlen=nums.size()+1;
        int left=0,right=0;
        int cursum=0;
        while(right!=nums.size()){
            cursum+=nums[right++];
            while(cursum>=s && left<right){
                if(right-left<minlen){
                    minlen=right-left;
                }
                cursum-=nums[left++];
            }
        }
        if(minlen==nums.size()+1)
            return 0;
        return minlen;
    }
};

```