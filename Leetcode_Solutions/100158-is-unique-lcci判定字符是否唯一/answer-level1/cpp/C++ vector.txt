![QQ截图20200217185309.jpg](https://pic.leetcode-cn.com/6dbfa9f7882f09043545b3c7e5b692493aa637d070df4cc015d35f51da2a8d59-QQ%E6%88%AA%E5%9B%BE20200217185309.jpg)
```
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution {
public:
    bool isUnique(std::string astr) {
        std::vector<char> result;
        result.clear();
        for(int i=0;i<astr.size();i++)
        {
            result.emplace_back(astr[i]);
        }
        int size=result.size();
        std::sort(result.begin(),result.end());
        result.erase(std::unique(result.begin(),result.end()),result.end());
        if(result.size()==size)
        {
            return true;
        }
        return false;
        
    }
};
```

