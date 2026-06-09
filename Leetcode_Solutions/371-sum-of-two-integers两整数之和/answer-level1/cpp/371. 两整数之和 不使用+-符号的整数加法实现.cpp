### 解题思路
此处撰写解题思路
step1:不考虑进位：xor
step2:仅考虑进位：and + <<
step3:当再无进位时结束循环
ps:当操作数为负数时左移会报错，故而有  carry = ((unsigned)(a&b))<<1;
### 代码
![371.jpg](https://pic.leetcode-cn.com/50820a50131f6b488a14a099a52260d5de7eff103e87ad3f8e2267a4eda729e8-371.jpg)

```cpp

class Solution {
public:
    int getSum(int a, int b) {
        int res, carry;
        do{
            //不考虑进位的+：xor
            res = a^b;
            //仅考虑进位： and 左移
            carry = ((unsigned)(a&b))<<1;
            a = res;
            b= carry;
        }while(b != 0);//loop直到没有新的循环为止

        return a;
    }
};
```

![371_1.jpg](https://pic.leetcode-cn.com/55dd6dfc530c3f16ff756f9779479bfca6e14fdd7219166b2b1c5a67b177c032-371_1.jpg)



![371_2.jpg](https://pic.leetcode-cn.com/8983a3841c221171157f4a47b15d957c2afd3fbfdbee5073a3f9ceb3d9acad4c-371_2.jpg)
