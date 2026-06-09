### 解题思路
如a = 2 b = 3 
a = 0010 b = 0011//假设存储字长为4位
1）a异或b左移一位可以求进位；
a&b = 0010
2）左移一位<<1 得0100
a与b得不含进位的和；
a^b = 0001
3）如果无进位，则2）即为所求和；如果有进位，递归再求1)2)直到无进位;

负数以补码存储是同样按照这种计算方式，但左移时需将其转换为无符号数左移
### 代码

```c
int getSum(int a, int b){
    int sum = a ^ b;
    unsigned int carry = (unsigned int) (a&b)<<1;
    return carry ? getSum(sum,carry) : sum;
}
```