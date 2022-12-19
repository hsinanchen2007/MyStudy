### 解题思路
其实没什么难点，主要还是要注意对1000000007进行取余，ansfib[i]=ansfib[i-1]+ansfib[i-2];就是对于斐波那契数列的基本算法，然后要注意一下n=0，n=1的两种情况就可以了

### 代码

```c
int fib(int n){
    int ansfib[101];
    ansfib[0]=0;
    ansfib[1]=1;
    if(n==0) return 0;
    else if(n==1) return 1;
    else
    {
         for(int i=2;i<=n;i++)
         {
            ansfib[i]=ansfib[i-1]+ansfib[i-2];
            ansfib[i]=ansfib[i]%(1000000007);
         }   
    }
    return ansfib[n];

}
```