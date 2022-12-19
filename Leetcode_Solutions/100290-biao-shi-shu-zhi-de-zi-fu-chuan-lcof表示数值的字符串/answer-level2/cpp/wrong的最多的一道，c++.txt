### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
int point = 0;

bool Unint(string s)
{   
    int p = point;
    while (s[point] >= '0' && s[point] <= '9')
    {
        point++;
    }
    return point > p;
}

bool ints(string s)
{
    int p = point;
    if (s[point] == '+' || s[point] == '-')
    {
        point++;
    }
    return Unint(s);
}

string trim(string s)
{   
    if (s.empty()) 
    {
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    if (s.find(" ") != s.npos)
    {
        s = "";
    }    
    return s;
}


bool isNumber(string s)
{   
    s = trim(s);
    if (s.empty())
    {
        return false;
    }

    bool numeric = ints(s);

    if (s[point] == '.')
    {
        point++;
        numeric = Unint(s) || numeric;
    }
    if (s[point] == 'e'|| s[point] == 'E')
    {   
        point++;
        numeric = numeric && ints(s);
    }
    return numeric && (point == s.size());
}
};
```

通过指针实现的方式简洁性最佳，测试用例还是很好的，出现首尾空格和中间空格的处理。

首尾空格处理：
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);

中间空格查找：
s.find(" ") != s.npos

指针最后的位置是是size，不是size - 1

注意||操作，a||b，a = true，则不会执行b，所以顺序不能反，优先执行那个需要明确