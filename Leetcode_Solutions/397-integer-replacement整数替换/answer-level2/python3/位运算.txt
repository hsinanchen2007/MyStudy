分析题目：
1. 偶数直接右移，只有一种选项
2. 奇数+1或者-1，有两种选项。
    2.1 显然，让每一步1的数目最少好处大，于是 0bxxx01 采用 -1； 0bxxx11 采用 +1；
    2.2 特殊情况 3，按上述原则+1后两次右移共需3次；减一后只需一次右移共2次，因此3采用-1操作
```Python []
class Solution:
    def integerReplacement(self, n: int) -> int:
        count = 0
        while n != 1:
            if (n & 1) == 0: # 偶数直接右移
                n >>= 1
            else:
                n += -1 if (n & 2) == 0 or n == 3 else 1  # 奇数01或者3减一，其他加1
            count += 1
        return count
```

```C++ []
class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) // 处理溢出，也可以直接用long tmp = n；
            return 32;
        int count = 0;
        while (n != 1) {
            if ((n & 1) == 0) { // 偶数直接右移
                n>>=1;
            }else {
                // 奇数 01减一,11加1,特殊情况n=3也是减1
                n += ((n & 2) == 0 || n == 3)? -1:1;
            }
            count++;
        }
        return count;
    }
};
```
