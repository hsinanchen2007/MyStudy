class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty() || nums.size()==1)
            return 0;
        int ans=0;
        ans=minijump(nums,nums.size());
        return ans;
    }
    int minijump(vector<int>& nums,int len){
        if(nums[0]>=len-1)
            return 1;
        int min=len-1;
        int cur=min;
        int j=0;
        for(int i=len-2;i>0;--i){
             j=len-1-i;
             if(nums[i]>=j)
                    cur=minijump(nums,i+1)+1;
             if(cur<min)
                min=cur;
        }
        return min;
    }
};