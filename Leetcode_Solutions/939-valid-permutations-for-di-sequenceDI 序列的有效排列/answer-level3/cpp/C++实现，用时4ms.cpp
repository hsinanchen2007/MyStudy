### 解题思路
1. 跟两个因素相关：
- 序列S
- 有效序列最后那位的数字
2. 定义函数F(n,a)表示：字符串S前n个字符组成的子串的有效排列中以数组n结尾的个数，0<=a<=n。
3. 动态方程：
- 当S的第n个字符为D时，F(n,a) = F(n-1, a) + F(n-1, a+1) + ... + F(n-1, n-1)，进一步得到 F(n, a) = F(n-1, a) + F(n, a+1);
- 当S的第n个字符为I时，F(n,a) = F(n-1, 0) + F(n-1, 1) + ... + F(n-1, a-1), 进一步得到F(n, a+1) = F(n, a) + F(n-1, a);


### 代码

```cpp
class Solution {
public:
    int numPermsDISequence(string S) {
        if (S.empty()) {
            return 0;
        }

        // 模
        int BASE = 1000000007;
        // S的长度
        const int SIZE = S.size();
        // 暂存结果的数组
        int F[200 + 1] = {1, 0};

        for (int i = 1; i <= SIZE; i++) {
            char ch = S[i - 1];
            if (ch == 'D') {
                // 考虑到取余操作，为了避免使用减法运算，从后往前更新数组
                F[i] = 0;
                for (int j = i - 1; j >= 0; j--) {
                    F[j] = (F[j + 1] + F[j]) % BASE;
                }
            }
            if (ch == 'I') {
                // 考虑到取余操作，为了避免使用减法运算，从前往后更新数组
                int next = 0;
                for (int j = 0, tmp = 0; j <= i; j++) {
                     tmp = F[j];
                     F[j] = next;
                     next = (next + tmp) % BASE;
                }
            }
        }

        // 将数组F前SIZE + 1个元素加起来，取余即为结果
        int res = 0;
        for (int i = 0; i <= SIZE; i++) {
            res = (res + F[i]) % BASE;
        }

        return res;
    }
};
```