```
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() < 3)
            return true;
        bool found = false, rule1 = true, rule2 = true;
        for(int i=0; i<A.size()-1;i++)
        {
            if(found == false && A[i] != A[i+1])
            {
                found = true;
                rule1 = A[i] < A[i+1];
            }
            
            if(found == true && A[i] != A[i+1])
            {
                rule2 = A[i] < A[i+1];
                if(rule1 != rule2)
                    return false;
            }
        }
        
        return true;
    }
};
```