![image.png](https://pic.leetcode-cn.com/dea8588e1bbea93e71f4ac6cd345a9a0baa8bd92723328acf5edb4f55b1ec532-image.png)
分类讨论一下，要么抢劫第一间，要么抢最后一间，要么两边都不抢，那不就是调用三次简单题的函数就行了嘛
结果随便一写真的击败了100%。。。。我傻了都。。。
rob1是前面的简单题的代码，完全照抄
```
class Solution {
public:
    int rob1(vector<int>& nums) {
        int num_size=nums.size();
        if(num_size==0)
        return 0;
        if(num_size==1)
        return nums[0];
        int dp[num_size]={0};
        
        dp[0]=nums[0] ;
        dp[1]=nums[1];
        int dp_max=dp[0];
        for(int i(2);i<num_size;i++)
        {
            if(dp_max>dp[i-2])
            dp[i]=dp_max+nums[i];
            else
            {
                dp[i]=dp[i-2]+nums[i];
                dp_max=dp[i-2];
            }
        }
        int max_result(-100);
        for(int i(0);i<num_size;i++)
        {
            if(dp[i]>max_result)
            {
                max_result=dp[i];
            }
        }
        return max_result;
    }
    int rob(vector<int>& nums) {
        int max_1(0);
        int max_2(0);
        int max_3(0);
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int head=nums[0];
        int tail=nums[nums.size()-1];
        nums.pop_back();
        max_1=rob1(nums);
        nums.push_back(tail);
        nums.erase(nums.begin());
        max_2=rob1(nums);
        nums.pop_back();
        max_3=rob1(nums);
        if(max_3>max_2)
        {
            if(max_3>max_1)
                return max_3;
            else{
                if(max_1>max_2)
                return max_1;
                else
                return max_2;
            }
        }
        else{
            if(max_1>max_2)
            return max_1;
            else{
                if(max_2>max_3)
                return max_2;
                else
                return max_3;
            }
        }
        
    }
};
```

