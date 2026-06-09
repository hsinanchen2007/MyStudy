
```c++ []
class Solution {
public:
    vector<string> result;
    string temp;
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 1);
        return result;
    }
    void dfs(string s, int index, int num)
    {
        if(index == s.size())
            return;
        if(num == 4 && (s.substr(index).size() > 3 || s.substr(index).size()==3 && s.substr(index) > "255" || s[index] == '0' && s.substr(index).size() > 1))
        {
            return;
        }
        if(num == 4 && index < s.size())
        {
            int len = temp.size();
            temp.append(s, index, s.size()-index);
            result.push_back(temp);
            temp = temp.substr(0, len);
            return;
        }
        for(int i = 1; i < 4; i++)
        {
            int len = temp.size();
            if(index + i > s.size())
                continue;
            if(i==3 && s.substr(index,3)>"255")
                continue;
            if(s[index] == '0' && i > 1)
                continue;
            temp.append(s.substr(index, i));
            temp += '.';
            dfs(s, index+i, num+1);
            temp = temp.substr(0, len);
        }
    }
};

```
