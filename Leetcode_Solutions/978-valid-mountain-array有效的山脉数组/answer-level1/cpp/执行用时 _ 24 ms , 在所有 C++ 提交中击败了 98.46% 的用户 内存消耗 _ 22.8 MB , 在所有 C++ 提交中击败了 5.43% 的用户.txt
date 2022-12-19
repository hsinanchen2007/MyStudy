```
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3) return false;
        int mountain=INT_MIN,idx;
        for(int i=0;i<A.size();++i){
            if(A[i]>mountain){
                mountain=A[i];
                idx=i;
            }
        }
        if(idx==0||idx==A.size()-1) return false;
        for(int i=idx;i>0;--i){
            if(A[i]<=A[i-1]) return false;
        }
        for(int i=idx;i<A.size()-1;++i){
            if(A[i]<=A[i+1]) return false;
        }
        return true;
    }
};
```

