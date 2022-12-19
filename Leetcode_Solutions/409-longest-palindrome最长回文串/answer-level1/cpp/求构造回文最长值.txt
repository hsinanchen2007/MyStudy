### 解题思路
1、回文数一定是字母成对出现或者是有且只有一个单字母加成对字母的出现
2、通过一个键值对来存取每个字母出现的次数，备于下面用来构造回文的情况
3、在循环过程中，可以知道当前的字母计数，每出现一次，如果是奇数则奇数统计自增，反之则奇数自减，偶数自增
4、最后可以通过偶数的对数和奇数的个数求出最大值


### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> letters;
        int oneCount = 0;
        int evenCount = 0;
        for (auto c : s)
        {
            auto iter = letters.find(c);
            if (iter != letters.end())
                iter->second++;
            else
                letters[c] = 1;

            if (letters[c]%2 == 1)
                oneCount++;
            else
            {
                oneCount--;
                evenCount++;
            }
        }

        return (oneCount == 0 ? evenCount*2 : evenCount*2 + 1);
    }
};
```