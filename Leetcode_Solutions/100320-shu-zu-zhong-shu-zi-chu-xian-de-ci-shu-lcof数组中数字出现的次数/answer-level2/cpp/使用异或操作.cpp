### 解题思路

明确异或的性质：
- 相异为1
- 0与任何数字异或的结果都是本身

总共分为三个步骤：
1. 将整个数组做异或操作，得到的是两个只出现一次数字异或的结果
2. 找出最后一位1
3. 根据最后一位1对原来的数字进行分组

找最后一位1的方法
- 首先根据位运算的性质 i & (i-1) 可以消除最后一位1
- 再将得到的结果与原数异或得到最后一位1
### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int _xor = 0; // 0与任何数异或都是原数
        for(auto num : nums)
            _xor ^= num;
        _xor = (_xor & (_xor - 1)) ^ _xor ;// 求出最后一位1

        int result1 = 0;
        int result2 = 0;
        for(auto num : nums){
            if(num & _xor) result1 ^= num; // 使用最后一位1进行筛选
            else result2 ^= num;
        }

        return vector<int>{result1,result2};

    }
};
```