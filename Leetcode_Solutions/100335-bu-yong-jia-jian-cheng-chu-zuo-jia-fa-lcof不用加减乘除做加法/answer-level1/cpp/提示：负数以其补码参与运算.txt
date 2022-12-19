### 解题思路
此处仅考虑负数运算，当a、b均为-1时；二者在计算机储存内容为：0XFFFFFFFF，二进制表示为：1111(...)1111,共计32位，其中首位为符号位。
则a^b=0,(a&b)<<1=1111(...)1110=-2,且(a&b)不等于0，再此执行while循环，则a^b=1111(...)1110=-2,(a&b)<<1=0。退出循环，结果为-2；
以上是在VS中的执行过程；

在leetcood中，因对负值的左移报错，可将负值转化为无符号数，举例说明:
int num=(unsigned int)(-1)，即将-1(0XFFFFFFFF，首位为符号位)转化为pow(2,33)-1(0XFFFFFFFF,首位为数字位)，然后pow(2,33)-1将隐式转换为有符号整数，即首位恢复符号位，num结果为-1；

### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        int sum;
        int carry ;
        while(1){
            int sum=(a^b);
            int carry =(unsigned int)(a&b)<<1;
            a=sum;
            b=carry;
            if(b==0){
                break;
            }
        }
        return a;
    }
};
```