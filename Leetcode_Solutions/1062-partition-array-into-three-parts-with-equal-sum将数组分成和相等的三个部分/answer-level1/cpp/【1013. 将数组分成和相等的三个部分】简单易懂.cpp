## 思路
根据提示，数组分为三个相等部分，则每个部分和为累加和的三分之一。
1. 累加求和，如果和不被3整除，则返回false；
2. 只要在数组最后一个数之前找到两个部分累加和为总和三分之一的连续数即满足条件。


### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (auto n : A) {
            sum += n;
        }
        if (sum % 3 != 0) return false;
        int tmp_sum = 0, cnt = 0;
        for (int i = 0; i < A.size() - 1 && cnt < 2; ++i) {
            tmp_sum += A[i];
            if (tmp_sum * 3 == sum) {
                ++cnt, tmp_sum = 0;
                continue;
            }
        }
        return cnt == 2;
    }
};
```