### 解题思路
参考答案写的简易动态规划,混个打卡,重点是如何定义状态以及状态转移的计算

### 代码

```cpp
//有点单调栈的味道,事实证明是错的
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result=0;
        int tmpres=0;
        int n=nums.size();
        stack<int> mystack;
        for(int i=0;i<n;++i){                
            while(!mystack.empty()&&nums[i]<=mystack.top()){
                mystack.pop();
                --tmpres;
            }
            /*
            if(mystack.empty()||nums[i]>mystack.top()){
                mystack.push(nums[i]);
                ++tmpres;
                result=max(result,tmpres);
            }
            
            mystack.push(nums[i]);
            ++tmpres;
            result=max(result,tmpres);
        }
        return result;
    }
};
*/
//尝试用动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result=1;
        int n=nums.size();
        if(n==0){return 0;}
        //base case
        vector<int> dp(n,1);
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                else{
                    continue;
                }
            }
            result=max(result,dp[i]);
        }
        return result;
    }
};
```