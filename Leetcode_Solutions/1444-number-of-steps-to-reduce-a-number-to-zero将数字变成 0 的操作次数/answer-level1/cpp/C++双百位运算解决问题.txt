### 解题思路
从二进制角度来看，奇数的最右边为1，那么完成奇数减一除以2的步骤，即两步，对于二进制来说就是右移一位。那么便循环判断，最后统计步数。由于最后肯定会到1,1到0步数只能为1，所以要count--再返回。
![image.png](https://pic.leetcode-cn.com/b4d1c6e24f1425fde830a3af15d4c4b653e04131cfc2a6d8b2bfd7c703c43b15-image.png)

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
          if(num==0) return num;
          int count=0;
          while(num)
          {
             if(num&1) count+=2;
             else count++;
             num>>=1;
          }
          count--;
          return count;
    }
};
```