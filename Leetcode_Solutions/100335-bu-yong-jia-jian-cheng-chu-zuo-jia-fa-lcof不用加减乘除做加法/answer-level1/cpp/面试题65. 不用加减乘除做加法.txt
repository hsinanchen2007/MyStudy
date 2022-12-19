```cpp
class Solution {
public:
    int add(int a, int b) {
        while(b)
        {
            //强制转化成unsigned int， 不然报错
            unsigned int carry = (unsigned int)(a & b) << 1; 
            a ^= b;
            b = carry;
        }
        return a;
    }
};



```