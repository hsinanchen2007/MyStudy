### 解题思路


### 代码

```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), cmp);
        for(int i = 0 ; i < d.size() ; ++i)
        {
            bool flag = true;
            int k = 0;
            for(int j = 0 ; j < d[i].length() ; ++j)
            {
                if((k = s.find(d[i][j], k)) != string::npos)
                {
                    k++;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return d[i];
        }
        string empty = "";
        return empty;
    }

    static bool cmp(string &a, string &b)
    {
        if(a.length() == b.length())
            return a < b;
        else
            return a.length() > b.length();
    }
};
```