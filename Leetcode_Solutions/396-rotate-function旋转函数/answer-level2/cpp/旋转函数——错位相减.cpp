### 解题思路
错位相减
sum = A[0] + A[1] + A[2] + ... + A[n -2] + A[n - 1]
weightsum0 = 0 * A[0] + 1 * A[1] + 2 * A[2] + ... + (n - 2)A[n -2] + (n - 1)A[n - 1]
weightsum1 = 1 * A[0] + 2 * A[1] + 3 * A[2] + ... + (n - 1)A[n -2] + 0 * A[n - 1]
weightsum1 = weightsum0 + sum - n * A[n - 1]
两个循环，找最大值就是结果

### 代码

```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.empty()){
            return 0;
        }
        int length = A.size();
        long sum = 0;
        long weightsum = 0;
        for(int i = 0; i < length; i++){
            sum += A[i];
            weightsum += (i * A[i]);
        }
        long result = weightsum;
        for(int i = length - 1; i >= 0; i--){
            weightsum = weightsum + sum - ((long)length * A[i]);
            result = max(result, weightsum);
        }
        return result;
    }
};
```