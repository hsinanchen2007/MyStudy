### 解题思路
位运算法是利用2的n次方的机器数的性质，也就是2的N次方 &（与运算） 2的N次方-1，结果为0
/*
bool isPowerOfTwo(long n){
    if(n==0){
        return 0;
    }
    return ((n&(n-1))==0);
}
*/

### 代码

```c
bool isPowerOfTwo(int n){
    while(n%2==0&&n>1){
        n=n/2;
    }
    if(n==1){
        return 1;
    }else{
        return 0;
    }
}
```