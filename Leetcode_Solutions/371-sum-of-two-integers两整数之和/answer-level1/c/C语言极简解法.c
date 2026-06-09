不能使用运算符+和-，则可以使用位运算来实现
**异或**：不带进位的加法
**进位**：位与，再左移一位
因此可以用**递归**思想，两数相加，先求异或，再加进位，如果仍产生进位，则将sum再与进位相加，直到进位为0结束。
对于负数，由于计算机存储的是补码，可以和正数使用相同的位运算逻辑，只是注意左移时要转换成无符号数的左移，否则会溢出
```
int getSum(int a, int b)
{
    int sum = a ^ b;
    unsigned int carry = (unsigned int)(a & b) << 1;
    if (carry != 0) {
        sum = getSum(sum, (int)carry);
    }
    return sum;
}
```
