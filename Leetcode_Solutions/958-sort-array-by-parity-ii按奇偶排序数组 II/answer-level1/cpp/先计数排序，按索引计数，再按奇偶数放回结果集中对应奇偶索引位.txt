### 解题思路
对于数值大小范围确定的数组，比如本题0~1000，很容易想到计数排序
### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.empty()) {
            return vector<int>();
        }
        vector<int> res(A.size());
        vector<int> tmp(1001, 0);
        for (auto n : A) {
            ++tmp[n];
        }
        // 结果集中奇数、偶数位对应的索引
        int even = 0, odd = 1;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] == 0) {
                continue;
            }

            if (i & 1) {
                while (tmp[i]) {
                    res[odd] = i;
                    odd += 2;
                    --tmp[i];
                }
            } else {
                while (tmp[i]) {
                    res[even] = i;
                    even += 2;
                    --tmp[i];
                }
            }
        }
        return res;
    }
};
```