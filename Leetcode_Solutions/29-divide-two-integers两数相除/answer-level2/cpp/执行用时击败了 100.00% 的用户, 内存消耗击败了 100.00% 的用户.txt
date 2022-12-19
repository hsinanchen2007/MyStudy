### 解题思路
不能用乘法，除法，取余，那么你必须得想到使用移位，如果你想不到，那肯定做不出来。
既然是移位，就得提一下这个算法的数学基础：泰勒展开。
这个相当于是2的幂次的展开，任何一个数K可以被表示为
    K = b0 * 2^0 + b1 * 2^1 + b2 * 2^2 + ... + bn * 2^n + ...
这道题目也是用类似的方式，将divisor不断进行移位，来得到2^n * divisor，然后得到累加倍数2^n，可以得到结果
这道题目的trick(可能是这些trick击败了100%的用户):
1. 先全部变成正数
2. if(abs(dividend) < abs(divisor))， 那么返回0
3. 在运算中使用long避免越界

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign;
        if( (dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0) ){
            sign = 0;
        }else{
            sign = 1;
        }
        long a = abs(dividend), cmp = abs(divisor);
        long res = 0, partial_sum = 1;
        int abs_divisor = cmp;
        if(a < cmp) return 0;
        while((cmp << 1) < a){
            cmp = cmp << 1;
            partial_sum = partial_sum << 1;
        }
        while(a >= abs_divisor){
            a -= cmp;
            res += partial_sum;
            //cout << "a: " << a << " cmp: " << cmp << " partial_sum: " << partial_sum << endl;
            while(cmp > a){
                cmp = cmp >> 1;
                partial_sum = partial_sum >> 1;
            }
        }
        if(sign == 1){
            if(-res < INT_MIN) return INT_MAX;
            else return -res;
        }else{
            if(res > INT_MAX) return INT_MAX;
            else return res;
        }
    }

};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 5.7 MB , 在所有 C++ 提交中击败了 100.00% 的用户