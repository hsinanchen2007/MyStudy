原问题可转化为求最长子数组和为0(0看为-1)；
我们定义一个unordered_map用于存放子数组的和及其对应的值，
每次更新结果ans与和为1的子数组长度中的最大值，即为所求。
```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_map<int,int>hash;
        hash[0]=0;
        int x=0;//子数组的和
        for(int i=0;i<n;i++){
            if(!nums[i])
                x--;
            else
                x++;
            if(hash.find(x)!=hash.end())
                ans=max(ans,i-hash[x]+1);
            else
                hash[x]=i+1;
        }
        return ans;
    }
};