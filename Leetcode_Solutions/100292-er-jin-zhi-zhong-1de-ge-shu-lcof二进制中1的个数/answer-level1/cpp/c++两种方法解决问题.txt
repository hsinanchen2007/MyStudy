### 解题思路
1.循环右移同时判断二进制数最右边的数是否为1，如果是就count++，直到给定数为0。
2.利用n=n&（n-1）使得最右边的1消去，循环判断消去了多少次才使得n等于0。
![image.png](https://pic.leetcode-cn.com/417a8fee5b9db600c11fd6ed90d32ac3f6f4179f5eb20e528e66c2af99cd6b0d-image.png)

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n)
        {
            if(n&1) count++;
            n>>=1;
        }
        return count;
    }
};
```