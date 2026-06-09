### 解题思路
1. 思路是将根据某种策略，将所有数据分成两种，且两个目标数字在不同的组之中
2. 毫无疑问，这两个数字肯定是不同的。因此二进制表示不完全相同。
3. 根据二进制表示某个二进制数为1或者0，区分数据成两组，同时相同的数据也会被分到一组
4. 组内互相与运算，产生结果

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sign = 0;
        for(int n : nums) sign ^= n;
        //sign和-sign与运算之后，会产生倒数第二位二进制数为1，其他为0
        sign &= -sign;
        int n1 = 0, n2 = 0;
        //根据sign分组
        for(int n : nums){
            if(n & sign) n1 ^= n;
            else n2 ^= n;
        }
        return {n1, n2};
    }
};
```