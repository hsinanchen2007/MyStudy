先把1，和小于0的判断了
在排除一切奇数，
大于等于二的还是偶数的，可以利用不断除2，一旦除完后是1的，肯定是，除完不是偶数的，排除。
```
bool isPowerOfTwo(int n){
    if(n==1) return true;
    if(n<=0) return false;
    if(n%2==1) return false;// 奇数不考虑
    while(n!=1)
    {
        n/=2;
        if(n==1) return true;

        if(n%2!=0) return false;
    }
    return true;
}
```

