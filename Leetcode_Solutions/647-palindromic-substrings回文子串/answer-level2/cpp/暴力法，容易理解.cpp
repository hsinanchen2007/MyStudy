### 解题思路
对于所有可能的子字符串进行判断
### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=1;i<=s.size();++i)
        for(int j=0;j<=s.size()-i;++j)
        if(isStr(s,j,j+i-1))
        ++count;
        return count;
    }
private:
    bool isStr(string &s,int begin,int end)
    {
        while(begin<end)
        {
            if(s[begin]!=s[end])
            return false;
            ++begin;
            --end;
        }
        return true;
    }
};
```