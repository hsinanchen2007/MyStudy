执行用时 :4 ms, 在所有 C++ 提交中击败了99.43%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了92.82%的用户

```
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        if(A[0]>=0){
            if(K%2!=0)
                A[0]=-A[0];
        return accumulate(A.begin(),A.end(),0);            
        }
        for(int i=0;i<K;i++){
            if(A[i]<0){
                A[i]=-A[i];
            }
            else if(A[i]==0)
                break;
            else{
                if((K-i)%2==0)
                    break;
                if(A[i]<A[i-1]){
                    A[i]=-A[i];
                }
                else
                    A[i-1]=-A[i-1];
                break;
            }
        }
        return accumulate(A.begin(),A.end(),0);
    }
};
```
