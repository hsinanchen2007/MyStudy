### 解题思路
字母实际是用 ASCII 码表示的，小写字母的范围是 65 ~ 90，大写字母则是 97 ~ 122。
所以可以直接用一个大小为 123 的数组记录每个字母出现的次数，优化后只需大小为 52 的数组。
时间复杂度为 O（S+J），S 和 J 分别是两个字符的长度。

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int counts[123] = {0};
        for (int i = 0; i < S.length(); i++)
        {
            counts[S[i]]++;
        }
        int res = 0;
        for (int i = 0; i < J.length(); i++)
        {
            res += counts[J[i]];
        }
        return res;
    }
};
```