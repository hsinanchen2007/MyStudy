1.枚举可以等分为两个合法子集的集合

2.判断是否可以分成（1）中的两个集合

```
class Solution {
public:
    bool check(vector<int> &nums, int x, int target){
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(x&(1<<i)) target-=nums[i];
            if(target<0) return false;
        }
        
        return target==0;
    }
    
    
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        int total = 0;        
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        
        if(n<4 || total%4) return false;        
        auto dp1 = vector<bool>(1<<n, false);
        for(int i=0;i<(1<<n);i++){
            dp1[i] = check(nums, i, total/4);
        }
        
        // split into two part, O(n^3)
        auto dp2 = vector<bool>(1<<n, false);
        for(int i=0;i<(1<<n);i++){
            if(!check(nums, i, total/2)){
                continue;
            }
            for(int j=i;j;j=(j-1)&i){
                if(dp1[j] && dp1[i-j]){
                    dp2[i] = true;
                    break;
                }
            }
        }
        
        for(int i=0;i<(1<<n);i++)
        {
            if(dp2[i] && dp2[(1<<n)-1-i]){
                return true;
            }
        }
        
        return false;
    }
};
```

比较短的code

```
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        int total = 0;        
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        
        if(n<4 || total%4) return false;        
        auto dp1 = vector<int>(1<<n, 0);
        for(int i=0;i<n;i++){
            dp1[1<<i] = nums[i];
        }
        for(int i=1;i<(1<<n);i++){
            int x = i&-i;
            dp1[i] = dp1[i-x] + dp1[x];
        }
        
        auto dp2 = vector<bool>(1<<n, false);
        for(int i=0;i<(1<<n);i++){
            if((dp1[i]<<1) != total){
               continue;
            }
            for(int j=i;j;j=(j-1)&i){
                if((dp1[j]<<2) == total && (dp1[i-j]<<2) == total){
                    dp2[i] = true;
                    break;
                }
            }
        }
        
        for(int i=0;i<(1<<n);i++)
        {
            if(dp2[i] && dp2[(1<<n)-1-i]){
                return true;
            }
        }
        
        return false;
    }
};
```
