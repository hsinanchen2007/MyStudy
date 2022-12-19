```
class Solution {
public://执行用时 :8 ms, 在所有 C++ 提交中击败了97.48%的用户
//可以把数组看作不动，下标循环左移n-1位
//记录第一次的结果，发现每次移动除了最大下标对应的值变为0了,其它位置都增加了（数组总和-最大下标对应的值）
    long long res,maxi,total,n;
    int maxRotateFunction(vector<int>& A) {
        n = A.size();
        for(int i=0;i<n;i++) {
            res += A[i]*i;
            total += A[i];
        }
        maxi = res;
        for(int i=n-1;i>0;i--) {
            maxi -= ((n-1)*(long long)A[i]);
            maxi += total-A[i];
            res = max(res,maxi);
        }
        return res;
    }
};
```
