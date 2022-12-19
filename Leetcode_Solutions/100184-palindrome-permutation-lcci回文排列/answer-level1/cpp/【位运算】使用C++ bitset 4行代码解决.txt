偶数次出现次数对应的bit为0，奇数次则为1
最后只需要统计bitset中1的个数是否是0或1即可。
建议大家学习一下bitset，用起来很方便。
```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> bits;
        for (char c : s) {
            bits.flip(c);
        }
        return bits.none() || bits.count() == 1;
    }
};
```