### 解题思路
比较简单的一道题
原理就是
若 a = x * y;
则 a % b = (x * y) % b;
x = mb + t1;
y = nb + t2;
x * y = (mb + t1) * (nb +t2) = nmb² + (m + n)b + t1t2;
a % b = t1t2
就是说 a 对 b 取余，相当于 a 的两个因子对 b 分别取余再相乘

所以我们就一边乘一边取余

我用的方法是从低位往高位乘
看过别人的题解，感觉高位往低位乘更方便点

我的思路是：
a ^ [1,2,3,4] = a ^ [4] * a ^ (10 * [1,2,3])
别人家孩子的思路是：
a ^ [1,2,3,4] = a ^ [4] * a ^ ([1,2,3] * 10)


### 代码

```cpp
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        int last = 1;
        int temp = 1;
        int length = b.size() - 1;
        a = a % 1337;
        for(int i = length; i >= 0; i--){
            last = result;
            temp = 1;
            if(i != length){
                for(int j = 0; j < 10; j++){
                    temp *= a;
                    temp = temp % 1337;
                }
                a = temp;
            }
            result = 1;
            for(int j = 0; j < b[i]; j++){
                result = result * a;
                result = result % 1337;
            }
            result = (last * result) % 1337;
        }
        return result;
    }
};
```