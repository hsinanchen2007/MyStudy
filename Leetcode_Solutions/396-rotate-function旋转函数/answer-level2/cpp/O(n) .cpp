```
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long n=A.size(),sum=0,tmp=0,ans;
        //由于有INT_MAX的测试点，也有包含负数的测试点，所以只能用long long处理
        for(int i=0;i<n;i++){
            sum+=A[i];
            tmp+=i*A[i];  //F[0]
        }
        ans=tmp;
        for(int i=n-1;i>=1;i--)  //分别计算F[1]...F[n-1]的情况，为tmp
        {
            tmp+=sum-n*A[i];  
            //找规律F[i]和F[i-1]的差别为 (sum-A[i])+(n-1)*A[i],也就是sum-n*A[i]
            ans=max(ans,tmp);
        }
        return ans;
    }
};
```
