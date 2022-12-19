### 解题思路
每一次**x % 10**获得的就是最后一位数据
**x / 10**就是消除掉最后一位的数据。
如**x=12345**
则有 **x % 10 = 5； x / 10 = 1234;**
下一步需要弄明白到底如何用**2^31-1**这样的形式来表示题目中给出的范围。

### 代码

```c
int reverse(int x){
    long result = 0;
    if(!(-2147483648 < x < 2147483647)) return 0;
    while(x!=0){
        result = result * 10 + x % 10;  
        x = x / 10;
      
    }  
    if(-2147483648 > result || result > 2147483647)                                return 0;
    else return result;
}
```