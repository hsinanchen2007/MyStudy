### 解题思路
使用map很简单

### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) 
    {
        map<char,int>m;
        for(int i = 0, N = s.size(); i < N; ++i)
        {
            switch(s[i])
            {
                case 'A':
                    m['A']++;
                    if(m['A'] > 1)
                        return false;
                    break;
                case 'L':
                    if(s[i+1] == 'L' && s[i+2] == 'L')
                    {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }
};
```