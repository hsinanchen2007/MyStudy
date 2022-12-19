### 解题思路
首先进行异或操作 然后将元素左移并且计算
![捕获.PNG](https://pic.leetcode-cn.com/4b4a2eebab5504878b5123d270cf2c01237abedd87a38fd336a9f3bfaf4cf547-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        //计算异或的值
        int n = x ^ y;

        //计算
        int counter = 0;

        //将每一个元素左移然后进行计算
        while ( n > 0)
        {
            counter += n & 1;
            n >>= 1;
        }

        return counter;
    }
};
```