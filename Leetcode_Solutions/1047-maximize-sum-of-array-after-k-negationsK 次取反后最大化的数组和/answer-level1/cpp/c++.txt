### 解题思路
童话里都是骗人的，自己写的快排除了内存上比sort函数少了1m之外，时间上没什么区别根本！

### 代码

```cpp
#include<algorithm>
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        for(int i=0;i<A.size()&&K>0;i++){
            if(A[i]<=0){
                A[i]=-A[i];
                K--;
            }else{
                break;
            }
        }
        sort(A.begin(),A.end());
        A[0]=(K%2!=0?-A[0]:A[0]);
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
        }
        return sum;
    }
};
```