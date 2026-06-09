### 解题思路
length 为字符串真实长度，即除去尾部空格


### 代码

```cpp
class Solution {
public:

    string replaceSpaces(string S, int length) {
        string str;
        for(int i=0; i < length; ++i)
        {
            if(S.at(i) != ' ')
                str.push_back(S.at(i));
            else
                str.append("%20");
        }
        return str;
    }

    // 没有扩容、复制 性能更好
    string replaceSpaces(string S, int length) {

        //统计前length个字符中的空格数量
        int space_count = 0; 

        for (int i = 0; i < length; ++i)
        {
            if (S.at(i) == ' ')
                ++space_count;
        }

        if (space_count == 0)
        {
            return S;
        }

        //返回的字符串
        int size = length + space_count * 2;
        string s(size, ' ');

        //复制、填充
        int j = 0;
        for (int i = 0; i < length; ++i)
        {
            if (S.at(i) != ' ')
            {
                s.at(j++) = S.at(i);
            }
            else
            {
                s.at(j++) = '%';
                s.at(j++) = '2';
                s.at(j++) = '0';
            }
        }

        return s;
    }

    //原地修改
    string replaceSpaces(string S, int length) {
        
        //统计前length个字符中的空格数量
        int space_count = 0; 

        for (int i = 0; i < length; ++i)
        {
            if (S.at(i) == ' ')
                ++space_count;
        }

        if (space_count == 0)
        {
            return S;
        }

        int p2 = length + 2 * space_count - 1;
        if (p2 + 1 < S.size())
        {
            S.at(p2 + 1) = '\0'; //可能S的空间有多，需要设置字符串结束符
        }

        for(int p1 = length - 1; p1 >=0; --p1)
        {
            if(S.at(p1) == ' ')
            {
                S.at(p2--) = '0';
                S.at(p2--) = '2';
                S.at(p2--) = '%';
            }
            else
            {
                S.at(p2--) = S.at(p1);
            }
        }

        return S;
    }
};
```