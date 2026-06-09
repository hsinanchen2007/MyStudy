
### 思路
直觉。。。。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        unordered_map<char, int> M, Temp;

        for ( size_t i = 0; i < chars.size(); ++i ) 
            ++M[chars[i]];
        
        for ( string word: words ) {
            int j;
            int len = word.length();
            Temp = M;
            for ( j = 0; j < len; ++j ) {
                if ( Temp.find(word[j]) != Temp.end() && Temp[word[j]] > 0 )
                    --Temp[word[j]];
                else
                    break;
            }
            if ( j == len )
                sum += len;
        }

        return sum;
    }
};
```