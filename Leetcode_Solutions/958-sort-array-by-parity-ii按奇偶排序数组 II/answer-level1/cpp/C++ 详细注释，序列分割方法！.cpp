### 解题思路
将原序列分为偶数列和奇数列，然后在偶数序列找到一个奇数后，再在奇数序列找一个偶数相交换。

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        // 1. 将原序列分为偶数序列和奇数序列，e 指向偶数，o 指向奇数
        for (int e = 0, o = 1; e < A.size(); e += 2) { 
            // 2. 在偶数序列找一个奇数
            if (A[e] % 2 == 1) {
                // 3. 在奇数序列找一个偶数
                while (A[o] % 2 == 1)
                    o += 2;
                
                // 4. 交换奇数和偶数
                swap(A[e], A[o]);
            }
        }

        return A;
    }
};
```