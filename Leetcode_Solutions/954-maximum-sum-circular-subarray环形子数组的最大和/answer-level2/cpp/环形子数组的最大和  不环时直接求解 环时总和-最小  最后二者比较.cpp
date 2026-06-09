```
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {

        int sum = 0;
        int maxsum = INT_MIN;

        int sum2 = 0;
        int minsum = INT_MAX;
        int allsum = 0;
        int count = 0;
        for(int i = 0; i < A.size(); i++) {
            sum = max(A[i], sum + A[i]);
            maxsum = max(maxsum, sum);
            int temp2 = sum2 + A[i];
            sum2 = A[i] > temp2 ? temp2 : A[i];
            minsum = minsum > sum2 ? sum2 : minsum;
            allsum += A[i];
        }

        int temp3 = allsum - minsum;
        if (temp3 == 0) {
            return maxsum;
        }
        else {
            return temp3 > maxsum ? temp3 : maxsum;
        }
    }
};
```
