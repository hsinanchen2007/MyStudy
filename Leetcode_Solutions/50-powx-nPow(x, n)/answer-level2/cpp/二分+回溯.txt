### 解题思路
x^n = x^(n/2) * x^(n/2) * x^(n%2)
利用这个递推关系可以把复杂度从O(n)减少到O(logn)
以n = 10,x = 2为例
2^10 = 2*5 * 2^5
2^5 = 2^2 * 2^2 * 2^1
2^2 = 2^1 * 2^1
转换成函数为
newPow(10, 2) = newPow(5,2) * newPow(5,2)
newPow(5,2) = newPow(2,2) * newPow(2,2) * 2
newPow(2,2) = newPow(1,2) * newPow(1,2)

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        return n < 0? 1/newPow(x, abs(n)) : newPow(x, abs(n));
    }

    double newPow(double x, long n){
        if(n < 2){
            if(n == 1){
                return x;
            }else{
                return 1;
            }
        }else{
            double half_res = newPow(x, n/2);
            if(n%2){
                return x * half_res * half_res;
            }else{
                return half_res * half_res;
            }
        }
    }
};
```

###结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 64.57% 的用户 
内存消耗 : 5.9 MB , 在所有 C++ 提交中击败了 100.00% 的用户