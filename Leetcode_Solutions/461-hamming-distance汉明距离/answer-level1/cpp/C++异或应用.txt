### 解题思路
1.将x和y异或得到num,即为x和y两数中(不同位)1的总个数
2.使用num & (num-1) 消除二进制位最后一位1,计数器count++，同时将num & (num-1)的结果赋给num
3.当num不为0时，说明其二进制位还有1,继续循环,当num为0时，此时count即为1的个数

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int num = x ^ y; // 二进制位不同为1
        while(num){
            ++count;
            num = num & (num-1); // 统计二进制位1的个数
        }
        return count;
    }
};
```