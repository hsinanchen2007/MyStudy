### 解题思路
为什么第一次提交编译出错？？

### 代码

```cpp
class Solution {
public:
    int strToInt(string str) {

        int i = 0;
        while(i < str.size() && str[i]==' ')
        {
            i++;
        }
        str = str.substr(i);

        std::regex re(R"(^[+\-]?\d+)");
        std::smatch num_match;

        if(std::regex_search(str, num_match, re))
        {
            string res = num_match[0];

            try{
                return stoi(res);
            }
            catch(std::out_of_range e)
            {
                return res[0] == '-'?  INT_MIN : INT_MAX;
            }
        }

        return 0;
    }
};
```