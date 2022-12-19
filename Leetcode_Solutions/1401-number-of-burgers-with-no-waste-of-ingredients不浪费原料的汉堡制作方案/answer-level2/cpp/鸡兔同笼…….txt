### 解题思路

不知道为什么这个题是中等难度……
奇数个tomatoSlices当然是不可能消耗完的了，因为需要的tomatoSlices都是偶数。
一个cheeseSlices最多消耗4个tomatoSlices，最少消耗2个tomatoSlices，不符合范围的也都不行。
剩下的就是鸡兔同笼问题

a + b = cheeseSlices
4a + 2b = tomatoSlices 

a = (tomatoSlices - 2 * cheeseSlices) / 2
b = cheeseSlices - a 

### 代码

```cpp
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2 == 1 || tomatoSlices > cheeseSlices << 2 || tomatoSlices < cheeseSlices << 1)
        {
            return {};
        }

        int a = (tomatoSlices - (cheeseSlices << 1)) >> 1;
        int b = cheeseSlices - a;

        return {a, b};
    }
};
```