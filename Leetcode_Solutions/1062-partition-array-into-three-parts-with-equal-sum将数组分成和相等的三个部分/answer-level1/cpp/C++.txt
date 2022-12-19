```c++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) {
            return false;
        }
        int target = sum / 3, i = 0, cur = 0;
        while (i < A.size()) {
            cur += A[i];
            if (cur == target) {
                break;
            }
            i++;
        }
        if (cur != target) {
            return false;
        }
        int j = i + 1;
        while (j < A.size()) {
            cur += A[j];
            if (cur == target * 2) {
                break;
            }
            j++;
        }
        if (j < A.size() - 1) {
            return true;
        }
        
        return false;
    }
};
```