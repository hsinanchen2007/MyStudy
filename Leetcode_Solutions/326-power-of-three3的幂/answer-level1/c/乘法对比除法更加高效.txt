### 解题思路
把参数跟3的幂次数对比的方法相比把参数一直除以3然后再对比条件所用的方法，时间及空间上所占用都来得更加高效

### 代码

```c
bool isPowerOfThree(int n){
    if(n<0)
        return false;
    long long int num = 1;
    while(n>=num)
    {
        if(n == num)
            return true;
        num*=3;
    }
    return n==1;
}
```