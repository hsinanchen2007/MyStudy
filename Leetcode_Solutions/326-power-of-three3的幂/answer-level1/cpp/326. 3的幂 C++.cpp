### 解题思路
1.若小于0直接返回false。
2.不断整除3迭代循环。
3.最后留下的因子是1说明次数只能被3整除，所以是3的幂返回true。
4.最后留下的因子不是1说明次数还能被其他质数整除，所以不是3的幂返回false。

### 代码

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1){
            return false;
        }
        while(n % 3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};
```