以前忘记在哪里见到过老师讲这个题，好像是叫“在线处理法”

核心思想是“循环累加更新sum，如果i循环到一个数，此时sum<0，说明之前的子序列都是‘累赘’，故更新sum=nums[i]”。
因此，本题只需要一次循环，但第一次提交时没有通过样例[-1]，因为把初试最长子序列和max设为了0，试着改成了nums[0]就A了，可能有些取巧2333

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,sum=0,max=nums[0];//注意[-1]的样例，max=0过不去
        for(i=0;i<nums.size();i++){
            if(sum<=0) sum=nums[i];
            else sum+=nums[i];
            if(sum>max) max=sum;
        }
        return max;
    }
};