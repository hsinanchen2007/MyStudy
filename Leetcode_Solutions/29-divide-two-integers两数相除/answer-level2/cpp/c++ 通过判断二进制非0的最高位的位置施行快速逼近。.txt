```
class Solution {
public:
    int inner2(int n) {
      if(n == -2147483648) {
        return 32;
      }
      n = ~(n - 1);
      for(int i = 31; i >= 1; --i) {
        int tmp = (n >> (i - 1)) && 1;
        if(tmp == 1) {
          return i;
        }
      }
      return 0;
    }
    int inner(int n1, int n2) {
      if( n1 > n2) {
        return 0;
      }
      int i = 1;
      int tmp = inner2(n1) - inner2(n2) - 1;
      for(int j = 0; j < tmp; ++j) {
        i = i << 1;
      }
      return i + inner(n1 - n2 * i, n2);
    }
    int divide(int dividend, int divisor) {
      if(dividend == (int)(1 << 31)) {
        if(divisor == -1) {
          return 0x7fffffff;
        }
        if(divisor == 1) {
          return dividend;
        }
      }

      int n1 = dividend;
      int n2 = divisor;
      if(n1 > 0) {
        n1 = - n1;
      }
      if(n2 > 0) {
        n2 = - n2;
      }
      int r = inner(n1, n2);
      if(dividend >= 0 && divisor >= 0 || dividend <=0 && divisor <= 0) {
        return r;
      }
      else {
        return -r;
      }
    }
};
```
这个题做了很久，暴露了我在处理这方面问题时对相关知识点理解不清晰熟练的问题，在此总结：
1.c++中整数除法向0取整：10 / (-3) = -3 ...1 而不是 -4 ... - 2.
2.c++中负整数的补码表示：在原码的基础上符号位不变，其余位取反，并+1.
3.int最小的负数(-2^31)的编码：符号位为1，其余位为0.