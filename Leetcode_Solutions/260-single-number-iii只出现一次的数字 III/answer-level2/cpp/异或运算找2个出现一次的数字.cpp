### 解题思路
首先我们将所有数字做一次异或，由于两个相同数字异或结果为0，那么我们最后得到2个目标数字的异或的结果
我们知道，当这两个数字在某个位不一样时，那么该位的异或结果一定为1，记为ai = 1
那么我们就可以将这堆数字分为两组，一组为ai位上为1的数字，另一组为ai位上位0的数字，
对这两组数字分别全部异或，就能得到两个目标数字
### 代码

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2,0);
        int _xor = 0;
        for(auto& n : nums)
            _xor ^= n;
        int mask = 1;
        while((_xor & mask) == 0){
            mask <<= 1;
        }
        // mask &= -mask;
        for(auto& n : nums){
            if(mask & n) res[0] ^= n;
            else res[1] ^= n;
        }
        return res;
    }
};
```