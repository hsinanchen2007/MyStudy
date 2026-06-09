### 解题思路
字符串可以被i,j,k三个指针分成4部分，对每一部分进行判断是否在0~255之间，如果都是的话，加入vector即可。
看似是O(n^3)的复杂度，实际上字符串长度最多为12个。

### 代码

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.size();
        if(len < 4 || len > 12) return vector<string>();

        vector<string> res;
        string str;

        for(int i = 0; i < len; i++)
        {   
            str.clear();
            if(!numString(s.substr(0, i))) continue;
            str += s.substr(0, i) + '.';
            for(int j = i; j < len; j++)
            {
                if(!numString(s.substr(i, j-i))) continue;
                str += s.substr(i, j-i) + '.';
                for(int k = j; k < len; k++)
                {
                    if(!numString(s.substr(j, k-j)) || !numString(s.substr(k, len-k))) continue;
                    str += s.substr(j, k-j) + '.' + s.substr(k, len-k);
                    res.push_back(str);
                    str.erase(j+2, len+2-j);
                }
                str.erase(i+1, len+3-i);
            }
        }

        return res;
    }

    bool numString(string ss)
    {
        int len = ss.size();
        if(len == 0 || len > 3) return false;
        if(len != 1 && ss[0] == '0') return false;

        int num = 0;
        for(auto str:ss)
        {
            num = 10*num + (str - '0');
        }
        if(num >= 0 && num < 256)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
```