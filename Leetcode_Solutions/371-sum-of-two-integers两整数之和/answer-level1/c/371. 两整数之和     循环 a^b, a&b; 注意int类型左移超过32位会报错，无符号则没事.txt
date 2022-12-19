### 解题思路
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3



### 代码

```c


int getSum(int a, int b){
    int low;
    unsigned int carry;

    while (true) {
        low = a ^ b;
        carry = a & b;
        if(carry == 0) break;
        //printf("low=0x%x carry=0x%x a=0x%x, b=0x%x\n", low, carry, a, b);
        a = low;
        b = (carry << 1);
    }

    return low;
}
```