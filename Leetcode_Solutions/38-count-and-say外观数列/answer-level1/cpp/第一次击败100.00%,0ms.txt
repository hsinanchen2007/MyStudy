### 解题思路
就是遍历上一次的字符串,计算连续的个数,生成新的字符串.

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string initStr = "1";
        if (n == 1)
            return initStr;

        for (int i = 2; i <= n; ++i)
        {
            string tmp = "";
            char c = ' ';
            int count = 1;
            //cout<<"initStr"<<initStr<<endl;
            for (auto s : initStr)
            {
                if (c == ' ')
                    c = s;
                else if (s == c)
                    count++;
                else
                {
                    tmp += (char)(count + '0');
                    tmp += c;
                    c = s;
                    count = 1;
                }
            }
            tmp += (char)(count + '0');
            tmp += c;
            //cout<<"tmp"<<tmp<<endl;
            initStr = tmp;
        }
        return initStr;
    }
};
```