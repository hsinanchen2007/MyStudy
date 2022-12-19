### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string gcd="";
        for(int i=1; i<=str1.size(); ++i)
        {
            string div=str1.substr(0,i);
            if(isDivisor(str1,div) && isDivisor(str2,div))
            {
                gcd=div;
            }
        }

        return gcd;
    }

    bool isDivisor(string str, string div)
    {
        int len_str=str.size(), len_div=div.size();
        if(len_str%len_div > 0) return false;
        int start=0;
        while(start<len_str)
        {
            if(str.substr(start,len_div) != div) return false;
            start+=len_div;
        }
        return true;
    }
};
```