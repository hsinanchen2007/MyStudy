### 解题思路
简单来说就是算里面的5的个数（其中25等价于5*5 所以算有两个5 以此类推）
输出要长整型啊

### 代码

```c
long trailingZeroes(int n){
    int tem=n,i;
    long sum=0,a=5;
    for(i=0;i<100;i++)
    {
        if(tem/a==0)
        break;
        sum+=tem/a;
        a*=5;
    }
    return sum;
}
```