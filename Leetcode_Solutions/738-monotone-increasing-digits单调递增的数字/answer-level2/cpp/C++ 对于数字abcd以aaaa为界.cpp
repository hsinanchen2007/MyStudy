![截屏2019-11-21下午11.16.17.png](https://pic.leetcode-cn.com/56d103f8eeff6070d5237ef11991b24cff971b20b91928f57964b558ccdf9a84-%E6%88%AA%E5%B1%8F2019-11-21%E4%B8%8B%E5%8D%8811.16.17.png)

纪念第一次顺利解出中等题嘿嘿

对于数字abcd，其中abcd表示各位数字，
如果aaaa>abcd，那么第一位只可能是(a-1)，其余位都可以取最大的9
如果aaaa<=abcd，那么第一位可以是a，问题就变为寻找bcd的满足题解的数字，然后结果就是a*1000+f(bcd),f()题解函数
形成了递归迭代的问题

```c++
int monotoneIncreasingDigits(int N) {
    if(N<10) return N;
    int construct;
    int main = N;
    int len = 0;
    while(main!=0){
        main = main / 10;
        len += 1;
    }
    int first = N / pow(10,len-1);
        
    int cache = 0;
    for (int i=0;i<len;i++)
        cache = cache*10 + first;

    if (cache > N){
        construct = first - 1;
        for (int i=0;i<len-1;i++)
            construct = construct*10 + 9;
        return construct;
    }
    else{
        construct = first * pow(10,(len-1));
        int child = N - construct;
        construct += monotoneIncreasingDigits(child);
        return construct;
    }

}
```