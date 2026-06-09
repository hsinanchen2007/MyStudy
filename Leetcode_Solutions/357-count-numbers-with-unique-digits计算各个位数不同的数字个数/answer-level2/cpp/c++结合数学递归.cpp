### 解题思路
满足题目的两位数的个数为9x9（第一位不为0）
满足题目的三位数的个数为9x9x8
...
满足题目的n位数的个数为9x(9x8x...x(10-(n-1)))   除第一个9以外，共n-1位。
f(0)=1;
f(1)=f(0)+9;
f(2)=f(1)+9x9;
f(3)=f(2)+9x9x8;
...
f(n)=f(n-1)+9x(9x8x...x(10-(n-1)))
### 代码

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int num=0,num_n=9;
        if(n==0)
            return 1;
        for(int i=1;i<n;i++)
            num_n*=10-i;
        num=countNumbersWithUniqueDigits(n-1) + num_n;
        return num;
    }
};
```