本题关键在于二分法的起始位置a与终止位置b怎么去变更，
经过思考，应由A[tem-1],A[tem],以及A[tem+1]共同决定
因为题目告知A。length>=3,
所以，当b-a>1时，A[tem-1],A[tem],以及A[tem+1]必须都在，
贴代码：
```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int a=0;
        int b=A.size()-1;
        int tem;
        while(b-a>1){
            tem =(a+b)/2;         
            if(A[tem]>A[tem-1]&&A[tem]>A[tem+1]) return tem;
            else if( A[tem]>A[tem-1]&&A[tem]<A[tem+1] ) a =tem;
            else if( A[tem]<A[tem-1] && A[tem]>A[tem+1] ) b = tem;

        }
        return tem;
    }
};
```
