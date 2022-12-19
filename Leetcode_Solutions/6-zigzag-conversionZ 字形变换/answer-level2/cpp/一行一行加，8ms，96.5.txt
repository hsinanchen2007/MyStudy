### 解题思路
找到每一行两个相邻元素的间隔规律就easy了。

顺便发现了一个leetcode的BUG,我这段代码提交了很多次，每次时间都不一样，这次用时最少，8ms

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if(numRows == 1)
            return s;
        int base_interval = 2*numRows-2;

        int pos = 0;
        while(pos<s.size()) //第一行和最后一行单独拎出来跑，避免中间的判断
        {
            res.push_back(s.at(pos));
            if(res.size() == s.size())
                return res;

            pos += base_interval;
        }

        for(int row=1;row<numRows-1;++row)
        {
            int interval = base_interval-2*row;
            pos = row;
            while(pos<s.size())
            {
                res.push_back(s.at(pos));
                if(res.size() == s.size())
                    return res;

                pos += interval;
                interval = base_interval - interval;
            }
        }

        pos = numRows-1;
        while(pos<s.size())//第一行和最后一行单独拎出来跑，避免中间的判断
        {
            res.push_back(s.at(pos));
            if(res.size() == s.size())
                return res;

            pos += base_interval;
        }
        return res;
    }
};
```