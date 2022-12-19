### 解题思路
统计空格次数 
构造新串，用原串填充，遇到空格则填充%20

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {

        int space_count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s.at(i) == ' ')
                ++space_count;
        }

        string s1(space_count * 2 + s.size(), ' ');

        int j = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s.at(i) == ' ')
            {
                s1.at(j++) = '%';
                s1.at(j++) = '2';
                s1.at(j++) = '0';
            }
            else
            {
                s1.at(j++) = s.at(i);
            }
        }

        return s1;
    }
};
```