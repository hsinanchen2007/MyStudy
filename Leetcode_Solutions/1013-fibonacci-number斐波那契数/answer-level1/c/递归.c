解题思路：递归
找出出口，进行递归操作。

int fib(int N){
    if (0 == N) {
        return 0;
    }
    if (1 == N) {
        return 1;
    }
    return fib(N - 1) + fib(N - 2);
}