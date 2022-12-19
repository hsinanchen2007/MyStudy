```
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int i = A.size()-1, carry = 0;
        while(i>=0 && K>0)
        {
            res.insert(res.begin(), (A[i]+K%10+carry)%10);
            carry = (A[i]+K%10+carry)/10;
            i--;
            K/=10;
        }

        while(i>=0)
        {
            res.insert(res.begin(), (A[i]+carry)%10);
            carry = (A[i]+carry)/10;
            i--;
        }

        while(K>0)
        {
            res.insert(res.begin(), (K%10+carry)%10);
            carry = (K%10+carry)/10;
            K/=10;
        }

        if(carry > 0) res.insert(res.begin(), carry);

        return res;
    }
};
```