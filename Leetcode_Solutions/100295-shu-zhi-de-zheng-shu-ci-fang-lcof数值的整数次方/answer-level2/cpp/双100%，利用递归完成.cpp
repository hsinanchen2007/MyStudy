### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :5.8 MB, 在所有 C++ 提交中击败了100.00%的用户
（1）递归函数如下：
```
    double get_pow(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        //每次右移，相当于除2
        double result = get_pow(x, n>>1);
        //平方返回
        result *= result;
        //如果n为奇数的话，则返回的值还需要乘以1个x
        if(n&1) result *= x;   
        return result;        
    }
```
（2）主函数如下
```
    double myPow(double x, int n) {
        double result = 1;
        int sign = 1;
        if(n<0){
            sign = -1;
            //注意，由于INT_MIN的绝对值比INT_MAX绝对值大，直接乘以-1会溢出
            if(n==INT_MIN){
                result = get_pow(x, INT_MAX) * x;
                return 1/result;
            }
            n = -1*n;
        } 
        result = get_pow(x, n);
        if(sign<0) result = 1 / result;
        return result;
    }
```


### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        int sign = 1;
        if(n<0){
            sign = -1;
            if(n==INT_MIN){
                result = get_pow(x, INT_MAX) * x;
                return 1/result;
            }
            n = -1*n;
        } 
        result = get_pow(x, n);
        if(sign<0) result = 1 / result;
        return result;
    }

    double get_pow(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        double result = get_pow(x, n>>1);
        result *= result;
        if(n&1) result *= x;   
        return result;        
    }
};
```