```
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size()==0)return 0;
        sort(A.begin(),A.end());
        int pos=0;
        while(pos<A.size()&&K>0&&A[pos]<0){
            A[pos]=-A[pos];
            ++pos;
            --K;
        }
        if(K>0&&K%2==1){
            if(pos==A.size()){
                A[pos-1]=-A[pos-1];
            }
            if(pos==0){
                A[pos]=-A[pos];
            }
            else{
                if(A[pos]>A[pos-1]){
                    A[pos-1]=-A[pos-1];
                }
                else{
                    A[pos]=-A[pos];
                }
            }
        }
        int ans=0;
        for(int i=0;i<A.size();++i){
            ans+=A[i];
        }
        return ans;
    }
};
```
