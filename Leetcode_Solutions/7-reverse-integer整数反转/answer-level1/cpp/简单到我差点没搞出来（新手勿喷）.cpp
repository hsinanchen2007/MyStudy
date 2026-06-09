### 解题思路
从这儿可以看出，学好数学的重要性。相当于是反着逐次乘以10然后累加。每循环一次，就把之前的所有位数升高一位。输入123.反过来就是第一步：res=3.第二步：res=2+3*10.第三步：res：res=1+32*10；

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
      long  int res = 0;
        while(x!=0)
        {
            res = x%10 + res*10;
            x = x/10;
        }
if (-2147483648<res&&res<2147483647)
        return res;
else
        return 0;
    }
};
```