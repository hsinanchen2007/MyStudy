lsum[i]:起始位置为i、长度为L的子数组和，msum[i]同理。
对于每个位置i开始的长度为L的子数组,搜索与其没有重复元素的所有长度为M的子数组（起始位置为j,判断条件为j+M <= i || j>=i+L），并保存最大值。
```
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        if(!n)return 0;
        vector<int>sum(n,0),lsum(n-L+1,0),msum(n-M+1,0);
        sum[0] = A[0];
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1]+A[i];
        }
        lsum[0] = sum[L-1];
        msum[0] = sum[M-1];
        for(int i=1;i<n;i++){
            if(i+L-1 < n){
                lsum[i] = sum[i+L-1] - sum[i-1];
            }
            if(i+M-1 < n){
                msum[i] = sum[i+M-1] - sum[i-1];
            }
        }
        int re = 0;
        for(int i=0;i<=n-L;i++){
            for(int j=0;j<=n-M;j++){
                if(j+M <= i || j>=i+L){
                    re = max(re,lsum[i]+msum[j]);
                }
            }
        }
        return re;
    }
};
```
