### 解题思路
此处撰写解题思路
只用算十的倍数的数位和，其余累加就好
### 代码

```cpp
class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> ans(37,0);
        ans[1]=1;
        int pre=1;
        int maxtimes=1;
        for(int i=2;i<=n;++i){
            if(i%10==0){
                int sum=getsum(i);
                ans[sum]++;
                pre=sum;
            }else ans[++pre]++; 
            maxtimes=max(maxtimes,ans[pre]);   
        }
        int ret=0;
        for(int i:ans){
            if(i==maxtimes) ret++;
        }
        return ret;
    }
    int getsum(int n){
        int ans=0;
        while(n!=0){
            ans+=n%10;
            n=n/10;
        }
        return ans;
    }
};
```