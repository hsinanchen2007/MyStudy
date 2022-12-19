将nums排好序后维护两个和sum1代表子序列的和，从后往前加，sum2表示序列剩余元素之和，从后往前减。当sum1>sum2时跳出循环，输出子序列。代码如下：
```
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
    int len=nums.size();
    if(len==1) return{nums[0]};
    int i,sum1=0,sum2=0;
    vector<int> ans;
    sort(nums.begin(),nums.end());
    for(i=0;i<len;i++)
        sum2+=nums[i];
    for(i=len-1;i>=0;i--)
    {
        sum1+=nums[i];
        sum2-=nums[i];
        ans.push_back(nums[i]);
        if (sum1>sum2) break; 
    }
    return ans;
    } 
};
```
