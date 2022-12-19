### 解题思路
1. 构造出临时字符串
2. 判断str1和str2能否整除临时字符串

详情看代码
### 代码

```cpp
class Solution {
public:
    bool isOk(string str1, string str2)   //判断str1是否能除尽str2
    {
        int pos = 0;
        while(pos < str1.size() - 1)
        {
            if (str1.compare(pos, str2.size(), str2) == 0)
            {
                pos += str2.size();
                continue;
            }

            return false;
        }

        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1.size() == 0 || str2.size() == 0)
        {
            return "";
        }

        int i, num = min(str1.size(), str2.size());
        string str3 = "";
        for (i = num; i  >= 1; --i)
        {
            if ((str1.size() % i  == 0) && (str2.size() % i == 0))  //成倍数关系
            {
                str3.assign(str1, 0, i);    //构造临时字符串str3
                
                if (isOk(str1, str3) && isOk(str2, str3))
                {
                    return str3;
                }
                str3 = "";
            }
        }

        return str3;
    }
};
```