知道题目是什么意思了还是很好解答的。通俗的来说，题目就是想让你判断一下，它给定的数组里面，是奇数多还是偶数多。
```
int minCostToMoveChips(vector<int>& chips) {
        int odd = 0, even = 0;
        for(int i = 0; i < chips.size(); ++i)
        {
            if(0 == chips[i] % 2)
                ++odd;
            if(1 == chips[i] % 2)
                ++even;
        }
        return odd > even?even:odd;
    }
```
