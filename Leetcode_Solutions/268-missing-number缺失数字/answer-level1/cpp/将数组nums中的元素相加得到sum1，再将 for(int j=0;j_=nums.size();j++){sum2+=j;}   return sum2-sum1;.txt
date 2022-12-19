### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        // int len=nums.size();
        // int i;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<=len;i++)
        // {
        //     if(nums.find(i)!=nums.end())//代表找到
        //         continue;
        //         return i;
        // }
        // return i;
        // vector<int> s(nums.size()+1);
        // for(int i=0;i<s.size();i++)
        // {
        //     s[nums[i]]=1;
        // }
        // for(int j=0;j<s.size();j++)
        // {
        //     if(s[j]!=1)  return j;
        // }
        // return 0;
        int sum=0;int sum2=0;
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];
        for(int j=0;j<=nums.size();j++)
        sum2+=j;
        return sum2-sum;
    }
};
```