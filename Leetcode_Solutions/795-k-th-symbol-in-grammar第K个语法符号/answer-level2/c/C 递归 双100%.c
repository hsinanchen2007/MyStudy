### 解题思路
非常简单的一个思路，向N的上一层找生成(N,K)的数，在根据上一层的数和K选择0或1即可
### 代码

```c
int kthGrammar(int N, int K){
    if(N==1||N==2&&K==1)
    return 0;
    if(N==2&&K==2)
    return 1;
    if(N>=2)
    {
        int a = kthGrammar(N-1,K/2+K%2);
        if(a==0)
        return K%2?0:1;
        if(a==1)
        return K%2;
    }
    return 1;//无用的，编译器的问题，不加通不过编译


}
```