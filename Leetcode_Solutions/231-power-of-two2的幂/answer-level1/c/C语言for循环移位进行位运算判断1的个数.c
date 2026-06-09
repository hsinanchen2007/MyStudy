### 解题思路
for循环移位取得第i位
进行if判断整数化为2进制数后的1的个数
只有在个数为1时才会是2的幂次方

此时此刻需要注意这个整数的符号问题
所以在一开始就对这个符号首先进行判断

### 代码

```c
bool isPowerOfTwo(int n){
    int judge = 0;
    if(n<=0) return false;
    for(int i = 31;i >= 0;i--){
        if((n>>(31-i))&1==1){
            judge++;
        }
        if(judge>1) return false;
    }
    return true;
}
```