### 解题思路
int型里最大的2次幂即为2^31

### 代码

```c
bool isPowerOfTwo(int n){
    if(n>0 && 2147483648%n==0) return true;
    else return false;
}
```