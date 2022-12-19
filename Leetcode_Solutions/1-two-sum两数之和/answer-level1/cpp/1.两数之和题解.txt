### 解题思路
我最开始的想法是暴力，就是一个n平方的复杂度；现在要学会利用hash ：c++ unordered_map

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> hash;
       for(int i=1;i<nums.size();i++)
       {
           hash[nums[i]]=i;
       }
       vector<int> ans;
       for(int i=0;i<nums.size();i++)
       {
           int one=nums[i];
           int two=target-one;
           int j=hash[two];
           if(j!=0&&j!=i)
           {
               ans.push_back(min(i,j));
               ans.push_back(max(i,j));
               break;
           }
       }
       return ans;
    }
};
```