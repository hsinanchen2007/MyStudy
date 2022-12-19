解题思路：
    从后向前遍历对于每个元素定义为A[K]
    A[K]的前面一个较大元素为A[J] A[J] > A[K]
    A[J]之前的最小元素为A[I]
    此时 I < J < K 如果满足A[I] < A[J] 则此题可解
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        //dp[i] 表示前n个元素最小值
        //O(n)
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; ++i)
        {
            dp[i] = min(dp[i-1],nums[i]);
        }
        //dp[k]前面一个较大元素dp[j]
        //O(n) next greater element n to 1
        vector<int> dns(nums.size(),-1);
        stack<int> s;
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            while(!s.empty() && nums[s.top()] <= nums[i])
            {
                s.pop();
            }
            
            dns[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        //O(n) judge
        for(int i = nums.size() - 1;i > 0; --i)
        {
            //k = i
            //j = dns[i]
            //ai = dp[dns[i] - 1]
            if(dns[i] > 0 && dp[dns[i] - 1] < nums[i])
            {
                return true;
            }
        }
        
        return false;
    }
};