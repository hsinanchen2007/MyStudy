### 解题思路
这是类似我爱的人曾让我写过的那道题

### 代码

```cpp
class Solution {
public:
    int dayOfYear(string date)
    {
        vector<string> ymd = split(date, '-');
        int y = stoi(ymd[0]), m = stoi(ymd[1]), d = stoi(ymd[2]);
        int months[] = {31, 28, 31 ,30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap(y)) months[1] = 29;
        int sum = d;
        for (int i = 0; i < m - 1; i++)
            sum += months[i];
        return sum;
    }
    bool isLeap(int y)
    {
        if (y % 4 == 0 && y % 100) return 1;
        if (y % 400 == 0) return 1;
        return 0;
    }
    vector<string> split(string str, char ch)
    {
        vector<string> subs;
        int length = 0;
        for (int i = -1, k = 0; k < str.length(); )
        {
            while (str[k] == ch) k++;
            i++;
            subs.push_back("");
            while (str[k] != ch && k < str.length())
            {
                subs[i] += str[k];
                k++;
            }
            length = i + 1;
        }
        return subs;
    }
};
```