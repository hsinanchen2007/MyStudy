### 解题思路
由于是求连续的三段和相等的非空子数组是否存在，自然地想到先求和，除以3以后就是每段子数组的和，若不能整除那必不存在。之后寻找第一段和第三段和等于目标和的子数组是否存在即可。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if (A.size() < 3)
            return false;
        
        int sum = 0;
        for (auto i : A)
            sum += i;
        
        int target = sum / 3;
        if (target + target + target != sum)
            return false;

        int i, j;

        int first = 0;
        for (i = 0; i < A.size() - 2; i++) {
            first += A[i];
            if (first == target)
                break;
        }
        if (i == A.size() - 2)
            return false;

        int last = 0;
        for (j = A.size() - 1; j > 1; j--) {
            last += A[j];
            if (last == target)
                break;
        }
        if (j == 1 || j - i < 2)
            return false;

        return true;
    }
};
```