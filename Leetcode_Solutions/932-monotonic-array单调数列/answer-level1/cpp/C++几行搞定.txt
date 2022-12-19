
```
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int flag=0,store;
        for(int i=0;i<A.size()-1;i++)
        {
            if(A[i]==A[i+1]) continue;
            if(A[i]!=A[i+1]) store=A[i]-A[i+1];
            if(flag*store<0) return false;
            flag=store;
        }
        return true;
    }
};
```
