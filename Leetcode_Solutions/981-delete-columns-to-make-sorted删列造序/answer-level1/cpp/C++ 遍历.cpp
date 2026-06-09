```c++
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int r = A.size();
        int c = A[0].size();
        int s = 0;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r - 1; j++) {
                if (A[j][i] > A[j + 1][i]) {
                    s++;
                    break;
                }
            }
        }
        return s;
    }
};
```