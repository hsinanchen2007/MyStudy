# Solution1 直接法
按题意，逐位运算。讲道理，不慢。
```C++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n>m) 
            n = n&(n-1);
        return n;
    }
};
```
# Solution1 减治法
首先，基本思路是，找到m的二进制最高位，若n的最高位也是此位，则mn间的任意元素均有此位，问题可减治；若n的最高位不同，则n以下2的最大次幂与m必为零，返回零。
然后考虑特殊情况，mn相等时可返回n，m小于2时必为零。
```C++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==n)
            return n;
        if(m<=1)
            return 0;
        int left = 2;
        while(left<=m/2)
            left *= 2;
        if(n/2>=left)
            return 0;
        return left+rangeBitwiseAnd(m-left, n-left);
    }
};
```