### 解题思路
挨个算出每一项，规律很简单，前一项中如果有相同的数，那么就是有几个相同数，下一项就描述为几个几

下一项可以理解为，每两个数是对前一项的一段的描述

因为n限定了不超过30，所以不用考虑前一项有10个1连续的这种情形

算法优化的关键在于n为几，就只需要算到第几层就行了，不需要算完

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        vector<string> strs;

        strs.push_back("1");
        for(size_t i=0;i<n-1;++i)
        {
            string tmp;
            string& str = strs.at(i);
            int count = 1;

            for(size_t j =0;j<str.size();++j)
            {
                if(j==str.size()-1)
                {
                    tmp.push_back(count+48);
                    tmp.push_back(str.at(j));
                }
                else if(str.at(j) == str.at(j+1))
                {
                    ++count;
                }
                else
                {
                    tmp.push_back(count+48);
                    tmp.push_back(str.at(j));
                    count = 1;
                }
            }

            strs.push_back(tmp);
        }

        return strs.at(n-1);
    }
};
```