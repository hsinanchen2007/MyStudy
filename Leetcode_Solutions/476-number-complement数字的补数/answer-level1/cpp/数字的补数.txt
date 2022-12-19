### 解题思路
注意此题不能直接取反，因为存在前导的0.
方法一：（异或）
当a为1110 0101，b为1111 1111，a^b = 0001 1010是a的取反.
所以二进制位数与num相同，且全为1的数tmp与num的异或即为答案。

5的二进制是：0101，7的二进制是： 0111，它们的异或为：0010，去掉前导的0即为5的取反。

方法二：(位运算) O(logn) 此方法比较绕
求出该数最高位1所在的位置，利用了 lowbit。
```cpp
        int tot;
        for (int i = num; i; i -= i & -i)
            tot = i & -i;
            //top 最高位为1 后面都为0  
        return ~num & (tot - 1);
```
### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        int tmp=1;
        while(tmp < num){
            tmp <<= 1;
            tmp += 1;
        }
        return (tmp xor num);
    }
};
```