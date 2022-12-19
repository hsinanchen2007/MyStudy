```cpp

class Solution {
public:
    int findKthNumber(int n, int k) {
        k --;
        int ans = 1;
        while (k > 0) {
            // 比如 n=13， 则1和2相差了1, 10 和 13相差了 13 + 1 - 10 
            long long first = ans, second = ans + 1, number = 0;
            while (first <= n) {
                number += min(static_cast<long long>(n + 1), second) - first;
                first *= 10;
                second *= 10;
            }
            if (number <= k) {
                k -= number;
                ans ++; // 1 --> 2 跳转到下一棵子树
            }
            else {
                k --; //除去自己，进入子树中
                ans = ans * 10;
            }
        }
        return ans;
    }
};
```