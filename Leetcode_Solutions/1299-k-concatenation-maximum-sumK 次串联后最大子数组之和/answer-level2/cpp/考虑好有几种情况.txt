1. 答案为 0。
2. 答案仅从当前不串联的数组中得到。(即k=1)
3. 答案从 k = 2 的串联结果得到，第一部分的后缀和的最大值加上第二部分的前缀和的最大值。
4. 答案从整个串联 k > 2 次后的结果得到，且一定是第一部分的后缀和的最大值，中间部分的总和，加上最后一部分的前缀和的最大值。
- 时间复杂度:只需要两次遍历所以是$O(n)$的复杂度
- 空间复杂度:只用了常数个变量辅助所以是$O(1)$
```c++
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        #define LL long long
        LL  n = arr.size(),maxn=INT_MIN,sum=0,mod = 1000000000+7;
        LL prefix=arr[0],suffix=arr[n-1],maxprefix=prefix,maxsuffix=suffix;
        for(int i=1,j=n-2;i<n;i++,j--){
            prefix+=arr[i];
            if(maxprefix<prefix)maxprefix=prefix;

            suffix+=arr[j];
            if(maxsuffix<suffix)maxsuffix=suffix;
        }
        for(int i=0;i<n;i++){
            if(sum<=0)sum = arr[i];
            else sum+=arr[i];
            if(maxn<sum)maxn = sum;
        }
        if(k==1)return maxn;
        return max(0ll,max(maxn,max(maxprefix+maxsuffix,(maxprefix + maxsuffix + (k-2)*prefix)%mod)));
    }
};
```