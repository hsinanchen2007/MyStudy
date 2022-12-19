```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, bit_xor<int>());
    }
};
```
- 这里用到了异或（xor），就是把数字的二进制形式按位计算，相同为1不同为0，然后返回位运算后的二进制代表的数字，那么相同的数字异或后为`0`
- `0`异或任何数都等于那个数，所以用`0`做起始值不会对结果有影响
- `accumulate`函数对整个序列进行递进式计算。每次计算都使用函数`bit_xor<int>`，以上次累积结果和当前数字作为参数，并将计算结果用于下次计算，有点递归的意思