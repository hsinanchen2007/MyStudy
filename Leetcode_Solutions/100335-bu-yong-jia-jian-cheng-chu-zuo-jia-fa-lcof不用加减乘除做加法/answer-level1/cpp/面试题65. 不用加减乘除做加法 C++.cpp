
### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        int sum, carry;
        do{
            // 如果不考虑进位的话，0 + 0 = 0, 0 + 1 = 1 + 0 = 1， 1 + 1 = 0,可以看做是异或操作    
            sum = a ^ b;   
            // 如果只考虑进位，1 + 1 = 10,其余都是0,可以看做是位与操作然后左移一位
            carry = (unsigned int)(a & b) << 1;

            // 然后将不考虑进位的和和进位相加，继续重复以上操作
            a = sum;
            b = carry; 
            
        }while(b != 0);  // 当进位不为0的时候继续相加

        return sum;
    }
};
```