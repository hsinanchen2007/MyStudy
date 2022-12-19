```
class Solution {
public:
    
    int sumFourDivisors(vector<int>& nums) {
        vector<int> ans(nums.size(),2);
        int temp=0;
        int ret = 0;
        int j;
        for(int i=0;i<nums.size();i++){
            for(j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0) {
                    if(j*j==nums[i]){
                    ans[i]=ans[i]+1;
                    }else{
                        ans[i]+=2;
                    }
                    temp+=nums[i]/j;
                    temp+=j;
                }
                if(ans[i]>=5) {
                    temp=0;
                    break;
                }
            }
            if(ans[i]==4) {
                ret+=1;
                ret+=nums[i]; 
                ret+=temp;
                temp=0;
            }
            temp=0;
         }
        if(ret!=0) return ret;
        return 0;
        
    }
};
```
![image.png](https://pic.leetcode-cn.com/0f8ec0147078d777c240c9c323232a9fbc66d604d0dc475c02a0920525b58188-image.png)

