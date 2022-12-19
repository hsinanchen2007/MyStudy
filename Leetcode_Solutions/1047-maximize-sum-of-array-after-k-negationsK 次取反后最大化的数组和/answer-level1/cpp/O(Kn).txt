### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int i=0;
        while(K){
            if(A[i]<0){
                A[i]=-A[i];
                i++;
            }
            else{
                break;
            }
            K--;
        }
        if(K>0){
            sort(A.begin(),A.end());
            while(K--){
                A[0]=-A[0];
            }
        }
        int sum=0;
        for(i=0;i<A.size();i++){
            sum+=A[i];
        }
        return sum;
    }
};
```