### 解题思路
根据提议，直接取反，但需要去掉前导的0值取反的数据
1. 计算num有效位的长度
2. 寻找一个数字flag，其有效比特位均为1，长度为num的有效长度
3. ~num & flag，如此去掉了num前导0值取反后的影响

### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        int res = ~num;
        int len = 0;
        while (num) {
            ++len;
            num >>= 1;
        }
        long flag = 1;
        flag <<= len;
        flag -= 1;
        return res & flag;
    }
};
```