### 解题思路
尾数0的个数取决于阶乘的结果与10的幂次的关系，而由于阶乘会从给定的n一直递减乘到1，这一过程有足够的因子2与所有的因子5相乘得到与5的个数相同的10，那么问题就变成了如何求解因子5的个数。由于5的i次幂含有i个因子5，故在判断因子5个数时，只需计算小于n的5的各次幂数的个数加和即可。

### 代码

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        //有0的条件是2*5或1*10或%10为0
        int num_zero=0;
        for(int i=1;pow(5,i)<=n;++i){
            num_zero+=n/(pow(5,i));
        }
        return num_zero;
    }
};
```