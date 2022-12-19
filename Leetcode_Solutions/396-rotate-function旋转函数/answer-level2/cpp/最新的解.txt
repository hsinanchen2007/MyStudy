### 解题思路
思路和之前的都一样，但是数据集出现[2147483647,2147483647]，这里用n*A[i]就会报错，建议用(n-1)*A[i] + A[i]

### 代码

```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size() == 0) {
            return 0;
        }
        int n = A.size();
        long long sum = 0;
        long long temp = 0;
        for(int i = 0; i < n; i++) {
            sum += A[i];
            temp += A[i] * i;
        }
        long long maxsum = temp;
        for(int i = 0; i < n; i++) {
            temp = temp - (sum - A[i]) + (n - 1)*A[i];
            maxsum = max(maxsum, temp);
        }
        return maxsum;
    }
};
```