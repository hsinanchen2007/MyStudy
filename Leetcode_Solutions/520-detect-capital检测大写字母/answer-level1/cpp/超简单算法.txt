
![批注 2020-03-20 184946.png](https://pic.leetcode-cn.com/13f0c423eda356d6cb6b42cbe655f10290772b9ec7db480976d5cbb820e8be03-%E6%89%B9%E6%B3%A8%202020-03-20%20184946.png)

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool start = isupper(word[0]);
        if(start)
        {
            int j =1;
            if(j<word.size())
            {
                if(isupper(word[j]))
                {
                    for(int i =2;i<word.size();++i)
                    {
                        if(!isupper(word[i]))
                            return false;
                    }
                }
                else
                {
                    for(int i=2;i<word.size();++i)
                    {
                        if(isupper(word[i]))
                            return false;
                    }
                }
            }
        }
        else
        {
            for(int i=1;i<word.size();++i)
            {
                if(isupper(word[i]))
                    return false;
            }
        }
        return true;
    }
};
```