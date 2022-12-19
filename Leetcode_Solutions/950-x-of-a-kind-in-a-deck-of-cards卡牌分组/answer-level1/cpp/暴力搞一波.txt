### 解题思路
- 统计出现次数
- 找到第一个比1大的最小数字x
- 2-x中必然有一个所有出现次数的公约数，并且整除x，暴力解决即可

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int card[10000] = {0};
        for (int i = 0; i < deck.size(); ++i)
            ++card[deck[i]];
        int x;
        for (int i =0; i < 10000; ++i)
        {
            if (card[i] == 1)
                return false;
            if (card[i] > 1)
            {
                x = card[i]<x? card[i]:x;
                break;
            }
        }
        for (int i = 2; i <= x; ++i)
        {
            if (x%i==0)
            {
                int flag = 1;
                for (int j = 1; j < 10000; ++j)
                {
                    if (card[j]%i != 0)
                        flag = 0;
                }
                if (flag)
                    return true;
            }  
        }
        return false;
    }
};
```