## 思路
假设每个数出现次数为$count_i$，每组都有X张牌且写着相同的数，可以得出X是所有数对应$count_i$的公约数，如果最大公约数为1则返回false。

### 代码
时间复杂度：O(NlogC)，其中 N 是卡牌的个数，C 是数组 deck 中数的范围，在本题中 C 的值为 10000。求两个数最大公约数的复杂度是 O(logC)，需要求最多 N - 1次
空间复杂度：O(N)

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() <= 1) return false;
        vector<int> hash(10000);
        for (int n : deck) {
            ++hash[n];
        }
        int t = hash[deck[0]];
        for (int i = 1; i < deck.size(); ++i) {
            t = gcd(t, hash[deck[i]]); //每两个数求最大公约数并更新
            if (t == 1) return false;
        }
        return true;
    }
};
```