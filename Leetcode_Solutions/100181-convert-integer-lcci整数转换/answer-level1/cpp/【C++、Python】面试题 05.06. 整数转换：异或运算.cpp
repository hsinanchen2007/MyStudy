### 异或运算 ###
#### 思路 ####
- 利用异或运算可以很方便地比较 $A$ 和 $B$ 的每一位是否不同，不相同的位为 $1$，相同的位为 $0$
- 问题于是转化为计算异或运算结果中 $1$ 的个数
#### 代码 ####
##### 逐位判断是否为 1 #####
- 略
##### 每次循环将末位 1 变为 0 #####
- `x &= (x - 1)`可以将`x`的最后一位`1`变为`0`，故循环直到`x`为`0`，循环的次数即为`x`中`1`的个数
- 注意负数的处理
```cpp []
/** 直接将异或运算的结果存储为无符号数 */
class Solution {
public:
    int convertInteger(int A, int B) {
        int res = 0;
        for (unsigned int diff = A ^ B; diff; diff &= diff - 1) ++res;
        return res;
    }
};
```
```python []
""" 异或运算的结果和 0xffffffff 进行与运算，忽略符号位 """
class Solution:
    def convertInteger(self, A: int, B: int) -> int:
        res, diff = 0, (A ^ B) & 0xffffffff
        while diff:
            res += 1
            diff &= diff - 1
        return res
```
##### 利用内置函数 #####
- C++ 中的`__builtin_popcount()`函数
- Python 中的`bin()`函数配合字符串的`count()`函数
```cpp []
class Solution {
public:
    int convertInteger(int A, int B) {
        return __builtin_popcount(A ^ B);
    }
};
```
```python []
class Solution:
    def convertInteger(self, A: int, B: int) -> int:
        return bin((A ^ B) & 0xffffffff).count('1')
```

#### 复杂度分析 ####
- 时间复杂度 $O(1)$，循环次数是常数级的，不会超过 $32$
- 空间复杂度 $O(1)$