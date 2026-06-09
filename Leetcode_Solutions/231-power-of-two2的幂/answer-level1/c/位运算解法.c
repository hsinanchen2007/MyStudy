### 解题思路
2次幂就是1,2,4,8...显然就是2进制数里面只有一位为1其他位为0。那就是求二进制中1的个数count，超过1则false，等于1则为true，小于1（即0）则为false。
那就将输入数每次右移一位和0x1位与，来判断最右位是否为1。最终通过1的个数得到返回值

### 代码

```c
bool isPowerOfTwo(int n){
    #define false 0
    #define true 1
    int count=0;
    if(n==0) return false;
    while(n!=0)
    {
        if(n&0x1) count++;
        if(count>1) return false;
        n = n>>1;
    }
    return true;
}
```