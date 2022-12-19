### 解题思路
用排列组合的思想来求得中1,2组合的数量。普通的计算会超最大值，即使使用了longlong类型，这里简单的优化了下(n+m)!/(n!*m!)的过程，使其至少在现有测试用例在long类型下不会溢出。c语言双百。

### 代码

```c
long int mul(int n,int m){
    long int result=1;
    for (int i=0;i<m;i++)
        result=result*(n+i+1)/(i+1);
    return result;
}//实现 (n+m)!/(n!*m!)
int climbStairs(int n){
    int kinds=1;
    int i=n-2;
    int numTwo=1;
    int numOne=i;
    while(i>0){
        if (numOne>numTwo)
            kinds=kinds+mul(numOne,numTwo);
        else
            kinds=kinds+mul(numTwo,numOne);
        //printf("%d %d %d\n",numOne,numTwo,kinds);
        i=i-2;
        numOne=i;
        numTwo++;
    }
    if (i==0)
        kinds++;
    return kinds;
}

```