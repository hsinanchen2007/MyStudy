```
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size() < 3) return false;
        for(int i=1;i<A.size();i++) A[i] += A[i-1];
        vector<int>::iterator first, second, third = A.end()-1;
        first = find(A.begin(), third - 1, (*third) / 3);
        if(first == third || (*third) != 3 * (*first))
            return false;
        else
        {
            second = find(first + 1, third - 1, (*third) / 3 * 2);
            if(second == third || (*second) != 2 * (*first))
                return false;
        }
        return true;
    }
};
```