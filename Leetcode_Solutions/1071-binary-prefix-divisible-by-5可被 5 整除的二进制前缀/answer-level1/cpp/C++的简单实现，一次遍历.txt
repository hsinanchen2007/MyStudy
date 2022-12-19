```
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>result(A.size());
        int pre=0;
        for(int i=0;i<A.size();++i){
            pre=pre*2+A[i];
            if(pre%5==0) result[i]=true;
            else result[i]=false;
            pre%=5;
        }
        return result;
    }
};
```
