![a7839ae7205be023e48fc8bc24b25b3.jpg](https://pic.leetcode-cn.com/516e7c1db325e5ff3ad216676c925d1779c958a004de91408b8679bdd0916719-a7839ae7205be023e48fc8bc24b25b3.jpg)


```
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        vector<int> p(2 * A.size());
        for(int i = 0; i < A.size(); ++i)
        {
            p[i] = A[i];
            p[i + A.size()] = A[i];
        }
        long maxsum = 0;
        long tempsum = 0;
        int k = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            maxsum += A[i] * k;
            tempsum += A[i];
            k++;
        }
        long temp = maxsum;
        for(int j = 1; j < A.size(); ++j)
        { 
            temp = temp + (A.size() - 1) * p[j + A.size() - 1] - (tempsum - A[j - 1]);
            tempsum = tempsum - A[j - 1] + p[j + A.size() - 1];
            maxsum = max(maxsum, temp);
        }
        return maxsum;
    }
};

```
