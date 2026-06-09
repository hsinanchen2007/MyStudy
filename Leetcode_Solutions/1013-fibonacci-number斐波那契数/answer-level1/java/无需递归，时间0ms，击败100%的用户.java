for循环，用两个变量保存前两项斐波那契数即可。并且变量交换时也无需临时变量。

class Solution {
    public int fib(int N) {
        if (N < 2) return N;
        int n1 = 0;
        int n2 = 1;
        for (int i = 2; i <= N; i++){
            n2 = n1 + n2;
            n1 = n2 - n1;
        };
        return n2;
    };
}