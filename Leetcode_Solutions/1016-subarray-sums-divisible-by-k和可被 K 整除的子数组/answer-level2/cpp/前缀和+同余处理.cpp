### 解题思路
处理子数组和的问题，通常采用前缀和。
有了前缀和之后，如果处理？考虑到如果后面的sum%K余数同前面的sum%K相同，那么就可以整除。
但是这里面需要考虑负数情况，-1可以和-1结合，也可以和K-1结合，有两种情况。其实可以使用map进行替换，节约空间，查找起来也会更加方便。

### 代码

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> preSum(A.size() + 1, 0);
        for (int i = 0; i < A.size(); i++) {
            preSum[i+1] = A[i] + preSum[i];
        }
        vector<int> leftNum(2*K, 0);
        int ans = 0;
        for (int i = 1; i < preSum.size(); i++) {
            int currentNum = preSum[i] % K;
            if (currentNum < 0) {
                ans += (leftNum[currentNum+K] + leftNum[currentNum+2*K]);
            } else {
                ans += (leftNum[currentNum+K] + leftNum[currentNum]);
            }
            leftNum[currentNum + K]++;
            if (currentNum == 0) {
                ans++;
            }
        }
        return ans;
    }
};
```