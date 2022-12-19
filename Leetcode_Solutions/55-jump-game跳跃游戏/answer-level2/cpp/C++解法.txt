贪心法则: 如果能跳到最后位置，那么一定能跳到其之前的某个位置。
```
bool canJump(vector<int>& nums) {
        int len=nums.size();
        int i=len-2,ans=len-1;
        while(i>=0)
        {
            if(nums[i]+i>=ans)
            {
                ans=i;
                i--;
            }
            else
            {
                i--;
            }
        }
        if(ans==0)
            return true;
        else
            return false;   
    }
```
