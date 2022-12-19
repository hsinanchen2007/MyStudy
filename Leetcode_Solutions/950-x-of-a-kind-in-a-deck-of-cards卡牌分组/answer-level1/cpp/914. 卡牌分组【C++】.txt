### 解题思路

思路还是很容易想到的，统计不同数字的个数，然后求所有不同数字的个数的最大公约数，也就是最终能分成的组中的数的个数。

如果数组中元素的个数不到2个，是肯定找不到符合要求的分组的，所以直接返回 `false` 即可。

我用了一个 `vector<pair<int, int>>` 的数组 `cards` 来统计不同数字的个数，`cards[i].first` 即数组中的某一个数字，`cards[i].second` 即这个数字在数组中的个数。然后遍历 `cards` 求所有的 `cards[i].second` 的最大公约数，返回值判断其是否大于或等于 `2` 即可。

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2)
            return false;
        //统计不同数字的个数
        vector<pair<int, int>> cards;
        for (auto d : deck) {
            bool exist = false;
            for (int i = 0; i < cards.size(); i++) {
                if (d == cards[i].first) {
                    cards[i].second++;
                    exist = true;
                    break;
                }
            }
            if (exist == false) {
                cards.push_back({ d,1 });
            }
        }
        int agcd = cards[0].second;//最大公约数
        for (int i = 0; i < cards.size(); i++) {
            agcd = gcd(agcd, cards[i].second);
        }
        return agcd >= 2;
    }

    //求最大公约数
    int gcd(int m, int n) {
        int t = 1;
        while (t != 0) {
            t = m % n;
            m = n;
            n = t;
        }
        return m;
    }
};
```