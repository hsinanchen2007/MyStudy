### 解题思路
代码思路转自其它大佬
dfs
有四个盒子，把所有的火柴分到四个盒子里，每根火柴放到其中一个盒子里
当所有火柴放完时，判断是否出现四个盒子的火柴长度相同
### 代码

```cpp
class Solution {
public:
    long long k;
    int v[4];
    bool dfs(vector<int>& nums,int pos){
           if(pos==nums.size()){
               return (v[0]==v[1]&&v[1]==v[2]&&v[2]==v[3]);
           } 
           for(int i=0;i<4;i++){
               if(v[i]+nums[pos]>k) continue;
                v[i]+=nums[pos];
                if(dfs(nums,pos+1)) return true;
                v[i]-=nums[pos]; 
           }
           return false;
    }
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4) return false;
        long long sum=0;
        int maxn=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];maxn=max(maxn,nums[i]);
        }
        if(sum%4!=0||maxn>(sum/4)) return false;
        k=sum/4;
        sort(nums.begin(),nums.end(),greater<int>());
        return dfs(nums,0);
    }
};
```