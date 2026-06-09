### 解题思路

除法运算，质因子

### 代码

```cpp
class Solution {
public:
    //n！=5^？
    int trailingZeroes(int n) {
     int  count =0;

     while( n>0)
     {
        count+=n/5;
        n/=5;
     }

     return count;
    }
};
```
![image.png](https://pic.leetcode-cn.com/a182129bb07f8cb629bcca9fdf062927ef5d329ff89b4b89964a681b1d3b6d41-image.png)
