### 解题思路

二分法

### 代码

```cpp
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(),A.end(),greater<int>());
        int n=A.size();
        if(n==1)return -1;
        int ret=A[n-1]+A[n-1];
        if(ret>=K)return -1;
        for(int i=0;i<n;i++){
            if(A[i]>=K)continue;
            auto tmp=lower_bound(A.begin()+i+1,A.end(),K-1-A[i],greater<int>());
            if(tmp==A.end())continue;
            ret=max(ret,A[i]+*tmp);
        }
        return ret;
    }
};
```