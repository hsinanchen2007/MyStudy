    我的方法效率不高，但胜在简单易懂。利用前缀和+动态规划
    因为给的A长度小于1000， 我们可以利用vector<int> v(1001)统计前缀和。同时要注意，两段连续子段和不能重合，所以先计算L段，在其前或后再计算M段最后 ans 不断更新最大值
```
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int ans = INT_MIN,sum1,sum2; //sum1记录长度为L的子段的和，sum2记录长度为M的子段的和
        int size = A.size();
        vector<int> v(1001);
        for(int i=1;i<=size;i++) //求前缀和
            v[i] = v[i-1] + A[i-1];
        for(int i=0;i<=size-L;i++) {
            sum1 = v[i+L] - v[i];
            sum2 = 0;
            for(int j=0;j<=i-M;j++) //sum1之前的长度为M的子段
                sum2 = max(sum2,v[j+M]-v[j]);
            for(int j=i+L;j<=size-M;j++) //sum1之后的长度为M的子段
                sum2 = max(sum2,v[j+M]-v[j]);
            ans = max(ans,sum1+sum2);
        }
        return ans;
    }
};
```
