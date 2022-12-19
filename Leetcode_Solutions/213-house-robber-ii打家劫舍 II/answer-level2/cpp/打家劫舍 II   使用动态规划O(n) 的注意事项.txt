
```cpp
class Solution {
public:
    //打劫问题升级版，因为是环形的，所以多了一个限制条件：
    //如果从第一户开始偷，那么最后一户就不能偷，下标:0~n-2
    //如果从第二户开始偷，最后一户就可以偷，下标为:1~n-1
    //环形问题分解为两条子序列，子序列使用动态规划，比较者最大值
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        return max(rob(nums,0,nums.size()-2),rob(nums,1,nums.size()-1));
    }

    //使用O(n)的动态规划时必须注意：
    int rob(vector<int>&nums,int first,int last){
        //根据first和last确定开辟dp数组的大小
        int cnt=last-first+1;
        vector<int> dp;

        //cur是dp数组的下标，不是nums的下标，cur从0，即dp的第一元素开始
        for(int cur=0;cur<cnt;cur++){
            //dp[0]插入第一个数
            if(cur==0)dp.push_back(nums[first]);
            //dp[1]插入第二个数
            else if(cur==1)dp.push_back(max(nums[first],nums[first+1]));
            else{
                //max里比的是dp数组里的值，不是nums数组的
                int tmp=max(dp[cur-1],dp[cur-2]+nums[first+cur]);
                dp.push_back(tmp);
            }
        }
        return dp.back();
    }
};
```