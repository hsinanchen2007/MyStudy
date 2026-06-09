### 解题思路
一开始就只想到了dfs，没想到0-1背包
貌似万物皆可动归
### 代码

```cpp
class Solution {
public:
    int f=0;
    void dfs(vector<int>& nums,int k,int sum,int pos){
        if(sum==k){
            f=1;
            return ;
        }
        if(pos<0) return ;//递归边界
        if(sum+nums[pos]>k) return ;//当前sum已经大于k了
        for(int i=pos;i>=0;i--){
            if(sum+nums[i]*(i+1)>=k){//如果当前sum和从0到当前i的i+1个数的和都小于k，则没必要继续递归
                dfs(nums,k,sum+nums[i],i-1);
                if(f) return ;
            }
        }
    }
    bool canPartition(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int sum=0;
       for(auto e:nums){
           sum+=e;
       } 
       if(sum%2==1) return false;//和为奇数不可能分成两个
       dfs(nums,sum/2,0,nums.size()-1);  
       if(f) return true;
       return false; 
    }
};
```