### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 1; i<word.size();++i)
        {
            if(i==1 && islower(word[i-1])&& isupper(word[i]))
               return false;
            else
            {
                if((islower(word[i-1])&&isupper(word[i]))||(isupper(word[i-1])&&islower                      (word[i])&&i>1))
                return false;
            }
        }
        return true;

    }
};
```