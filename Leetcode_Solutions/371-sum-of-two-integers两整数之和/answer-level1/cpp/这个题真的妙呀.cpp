##### 题感：这个题就非常有意思了，题解如此：`两个整数a, b; a ^ b是无进位的相加； a&b得到每一位的进位；让无进位相加的结果与进位不断的异或， 直到进位为0；` 真的强。 但是负数在计算机里面是用的补码 -- `正数的补码和原码相同，负数的补码为除了第一位符号位之外，其他位0变1,1变0，并且最后再加1` , 于是就会出现这么一组数据： -1,1 ，其中正数 1 会一直左移一位到第 32 位去，所以要转成 `unsigned int` 。 

```C++
class Solution {
public:
    int getSum(int a, int b) {
        int sum1 = a ^ b , sum2 = a & b ; 
        while(sum2){
            a = sum1 ; b = (unsigned int )sum2 << 1; 
            sum1 = a ^ b ; 
            sum2 = a & b ; 
        }
        return sum1 ;
    }
};
```