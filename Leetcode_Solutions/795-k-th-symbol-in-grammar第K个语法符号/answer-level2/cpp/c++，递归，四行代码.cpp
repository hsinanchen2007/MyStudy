运用*递归*的思想，
*子问题：*
第K个数值是多少，去问上一排(K + 1)/2位置的数值.
而(K + 1)%2为零时，第K个数值与上一排(K + 1)/2位置的数值相等，反之相反。
*终止条件：*
当K为1时对应数值为0，当K为2时对应为1；

```
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1 || N == 2)
            return K - 1;
        int temp = kthGrammar(N - 1, (K + 1)/2);
        return (K + 1)%2 == 0?temp:(temp + 1)%2;
    }
};
```
执行用时 :4 ms, 在所有 cpp 提交中击败了64.37%的用户

内存消耗 :8 MB, 在所有 cpp 提交中击败了89.36%的用户
