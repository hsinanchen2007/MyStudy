### 解题思路
挺好的题，就是感觉题目稍微描述地有点不清晰

### 代码

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        char vowels[6] = {'a', 'e', 'i', 'o', 'u'};
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            int k1, k2;
            for(k1 = 0 ; k1 < 6 ; ++k1)
            {
                if(tolower(s[i]) == vowels[k1])
                    break;
            }
            for(k2 = 0 ; k2 < 6 ; ++k2)
            {
                if(tolower(s[j]) == vowels[k2])
                    break;
            }
            if(k1 == 6)
                i++;
            if(k2 == 6)
                j--;
            if(k1 < 6 && k2 < 6)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
```