### 解题思路
常规思路解题即可

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if ( s.empty() )
            return 0;

        unordered_map<char, int> M;
        for ( char ch: s )
            ++M[ch];

        int length = 0, haveOdd = 0;
        for ( auto iter = M.begin(); iter != M.end(); ++iter ) {
            if ( iter->second % 2 == 1 ) {  // iter->second 为奇数
                haveOdd = 1;
                length += iter->second - 1;
            }
            else  // iter->second 为偶数
                length += iter->second;
        }
        // 若存在奇数个字符，则将其中一个字符放回文中心
        return 1 == haveOdd ? length + 1 : length;
    }
};

```