定义函数f(n, m)表示最后删除元素的值，因为删除后的序列和原始序列的最后删除的元素是相同的，所以f(n, m)=f'(n-1, m)，f'函数和f函数的意思一样，只是f'中的n-1个序列不连续，所以用另一个函数来过渡，这时我们需要将不连续的序列进行映射成连续的序列。
假设第一个删除的元素为k，则序列变为0,1,2...,k-1,k+1,...,n-1，不连续了，所以需要映射
k+1 -> 0
k+2 -> 1
...
n-1 -> n-k-2
0 -> n-k-1
...
k-1 -> n-2
总结：p(x)=(x-k-1)%n，x表示映射前的值，p(x)表示映射后的值
f(n-1, m)=p[f'(n-1, m)] = [f'(n-1, m)-k-1]%n=[f(n, m)-k-1]%n
所以得到了一个公式f(n-1, m)=[f(n, m)-k-1]%n
将其逆映射得f(n, m)=[f(n-1, m)+k+1]%n
递归
int lastRemaining(int n, int m) {
    if(n == 1 || m == 1)
        return n - 1;
    return (lastRemaining(n - 1, m) + m) % n;
}
迭代
int lastRemaining(int n, int m) {
    if(n == 1 || m == 1)
        return n - 1;
    int f = 0;
    for(int i = 2; i <= n; ++i)
        f = (f + m) % i;
    return f;
}