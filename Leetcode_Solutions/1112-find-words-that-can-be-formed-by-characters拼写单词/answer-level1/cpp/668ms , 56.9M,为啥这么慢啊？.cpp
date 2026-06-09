### 解题思路


### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count = 0;
        map<char, int> cMap;
        for(auto c : chars)
        {
            if(cMap[c])
            {
                cMap[c] += 1;
            }
            else
            {
                cMap[c] = 1;
            }
        }
        for(auto word : words)
        {
            map<char, int> tempMap;
            bool fit = true;
            for(auto c : word)
            {
                if(tempMap[c])
                {
                    tempMap[c] += 1;
                }
                else
                {
                    tempMap[c] = 1;
                }

                if(!cMap[c] || tempMap[c] > cMap[c])
                {
                    fit = false;
                    continue;
                }
            }
            if(fit)
            {
                count += word.length();
            }
        }

        return count;
    }
};
```