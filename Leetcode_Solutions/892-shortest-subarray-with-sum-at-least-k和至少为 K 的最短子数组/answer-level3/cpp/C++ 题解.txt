```
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int res = -1;
        while (right < A.size()) {
            sum += A[right];
            if (sum <= 0) {
                sum = 0;
                ++right;
                left = right;
                continue;
            }
            int i = right;
            while (A[i] < 0) {
                A[i - 1] += A[i];
                A[i] = 0;
                --i;
            }
            if (sum >= K) {
                while (left <= right && sum - A[left] >= K)
                    sum -= A[left++];
                if (res == -1 || (right - left + 1) < res)
                    res = right - left + 1;
            }
            ++right;
        }
        return res;
    }
};
```
