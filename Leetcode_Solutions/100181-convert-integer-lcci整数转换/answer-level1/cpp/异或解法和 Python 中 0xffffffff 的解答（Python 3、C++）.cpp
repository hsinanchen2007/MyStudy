### 解题思路
这个问题看似复杂，实则不难，我们发现只有该位置不同时才需要转换，因此想到使用异或得到结果 c，最后数一下 c 中 1 的个数即可。

*知识小贴士*
真值|原码|反码|补码|备注
:-:|:-:|:-:|:-:|:-:
+ 1|0 00000001|0 00000001|0 00000001|正数的原码反码补码相同
- 1|1 00000001|1 11111110|1 11111111|负数的补码是符号位不变其余取反加 1
### 方法一：一行
```python []
lass Solution:
    def convertInteger(self, A: int, B: int) -> int:
        return bin((A & 0xffffffff) ^ (B & 0xffffffff)).count('1')
```
```cpp []
class Solution {
public:
    int convertInteger(int A, int B) {
        return __builtin_popcount(A ^ B);
    }
};
```

### 方法二
不断对 c 进行移位操作，然后检查最低有效位。
```python []
class Solution:
    def convertInteger(self, A: int, B: int) -> int:
        res = 0
        c = A ^ B
        for i in range(32):
            res += c >> i & 1
        return res
```

```cpp []
class Solution {
public:
    int convertInteger(int A, int B) {
        int res = 0;
        for (unsigned c = A ^ B; c != 0; c = c >> 1)
            res += c & 1; // 数一数 c 中有几个 1
        return res;
    }
};
```

### 方法三
不断翻转最低有效位，计算需要多少次 c 会变成 0。其中 ⚠️`c = c & (c - 1)` 是一个位操作的常用问题，可以特别注意一下。
```python []
class Solution:
    def convertInteger(self, A: int, B: int) -> int:
        C = (A & 0xffffffff) ^ (B & 0xffffffff)
        cnt = 0
        while C != 0: # 不断翻转最低位直到为 0
            C = C & (C - 1) # 清除最低位
            cnt += 1
        return cnt
```
```cpp []
class Solution {
public:
    int convertInteger(int A, int B) {
        int res = 0;
        for (unsigned c = A ^ B; c != 0; c = c & (c - 1))
            res ++;
        return res;
    }
};
```
### 复杂度分析
- 时间复杂度：$O(1)$。
- 空间复杂度：$O(1)$。

### 为什么要和 oxffffffff 作与运算
一般来讲，整形数在内存中是以 **补码** 的形式存放的，输出的时候同样也是按照 **补码** 输出的。

但是在 Python 中，情况是这样的：
1. 整形是以 **补码** 形式存放的，输出的时候是按照 **二进制** 表示输出的；
2. 对于 $bin(x)$（$x$ 为 **十进制负数**），输出的是它的原码的二进制表示加上一个负号，方便查看（方便个🔨🔨🔨）
3. 对于 $bin(x)$（$x$ 为 **十六进制负数**），输出的是对应的二进制表示。

所以为了获得十进制负数的补码，我们需要手动将其和 0xffffffff 进行与操作，得到一个十六进制数，再交给 `bin()` 转化，这时内存中得到的才是你想要的补码。 

```python
a = bin(-3)
print(a)

a = bin(3)
print(a)

b = bin(-3 & 0xffffffff)
print(b)

c = bin(0xfffffffd)
print(c)

# 输出
# -0b11
# 0b11
# 0b11111111111111111111111111111101
# 0b11111111111111111111111111111101
```

