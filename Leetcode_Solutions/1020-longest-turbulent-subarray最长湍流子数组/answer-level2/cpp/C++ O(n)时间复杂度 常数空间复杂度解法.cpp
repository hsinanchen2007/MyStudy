```
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.empty()) {
            return 0;
        }
        int curRes = 0, res = 0, lastSign = -2;
        for(int i = 1; i < A.size(); i++) {
            int thisSign = 0;
            if(A[i] > A[i - 1]) {
                thisSign = 1;
            } else if(A[i] < A[i - 1]) {
                thisSign = -1;
            } else {
                thisSign = 0;
            }
            if(thisSign == 0) {
                curRes = 0;
            } else if(thisSign == lastSign) {
                curRes = 1;
            } else {
                res = max(res, ++curRes);
                lastSign = thisSign;
            }
        }
        return res + 1;
    }
};
```
